#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

string s;

char M[50][50];
int dot[50][4];
int vis[50];
int indegree[50];
vector<int> G[50];

int h,w;
void init(int N){
    memset(dot,-1,sizeof(dot));
    memset(M,0,sizeof(M));
    memset(indegree,0,sizeof(indegree));
    memset(vis,-1,sizeof(vis));
    for(int i = 0; i <= N; i++){
        G[i].clear();
    }
}

void addEdge(int v, int u){
    G[v].push_back(u);
    indegree[u]++;
}


void judgeEdge(char c){
    int x1 = dot[c-'A'][0];
    int y1 = dot[c-'A'][1];
    int x2 = dot[c-'A'][2];
    int y2 = dot[c-'A'][3];
    set<char> s;
    for(int i = x1; i <= x2; i++){
        if(i == x1 || i == x2){
            for(int j = y1; j <= y2; j++){
                if( c != M[i][j]) s.insert(M[i][j]);
            }
        }else{
            if(c != M[i][y1]) s.insert(M[i][y1]);
            if(c != M[i][y2]) s.insert(M[i][y2]);
        }
    }
    set<char>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        addEdge(c-'A',(*it)-'A');
    }
}



void dfs(int q,string a){

	if(q == s.size()){
		printf("%s\n",a.c_str());
		return;
	}
	
	for(int i = 0; i < 26; i++){
		if(vis[i] == 0 && indegree[i] == 0){
			a += 'A'+i;
			indegree[i] = -1;
			vis[i] = 1;
			
			for(int j = 0; j < G[i].size(); j++){
				indegree[G[i][j]]--;
			}
			dfs(q+1,a);
			for(int j = 0; j < G[i].size(); j++){
				indegree[G[i][j]]++;
			}
			a.erase(a.size()-1);
			indegree[i] = 0;
			vis[i] = 0;
		}
	}
}


int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&h,&w) != EOF){
    init(50);
    for(int i = 0; i < h; i++){
        scanf("%s",M[i]);
        for(int j = 0; j < w; j++){
        	if(M[i][j] == '.')continue;
            if(dot[M[i][j]-'A'][0] == -1 && dot[M[i][j]-'A'][1] == -1){
                dot[M[i][j]-'A'][0] = i;
                dot[M[i][j]-'A'][1] = j;
                dot[M[i][j]-'A'][2] = i;
                dot[M[i][j]-'A'][3] = j;
            }else{
                dot[M[i][j]-'A'][0] = min(i,dot[M[i][j]-'A'][0]);
                dot[M[i][j]-'A'][1] = min(j,dot[M[i][j]-'A'][1]);
                dot[M[i][j]-'A'][2] = max(i,dot[M[i][j]-'A'][2]);
                dot[M[i][j]-'A'][3] = max(j,dot[M[i][j]-'A'][3]);
            }
        }
    }
    s = "";
    for(int i = 0; i < 26; i++){
        if(dot[i][0] != -1){
			s += 'A'+i;
            vis[i] = 0;
		}
    }
    for(int i = 0; i < s.size(); i++){
        judgeEdge(s[i]);
    }
	dfs(0,"");
    }
    return 0;
}
