#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 30;
const int INF = 0x3f3f3f3f;


char map[MAXN];
int inde[MAXN];
int vis[MAXN];
int tol;

vector<int> Edge[MAXN];

void addEdge(int f,int t){
    if(find(Edge[f].begin(),Edge[f].end(),t) == Edge[f].end()){
        Edge[f].push_back(t);
        inde[t]++;
    }

}

bool isAllVis(int n){
    for(int i = 0; i < n; i++){
        if(vis[i] == 0) return false;
    }
    return true;
}

void topSort(int n){
    queue<int> q;
    string ss = "";
    int curNum = 0;
    for(int i = 0; i < n; i++){
        if(inde[i] == 0){q.push(i);}
    }
    while(q.size()){
        int v = q.front();q.pop();
        ss += 'A'+v;
        curNum++;
        vis[v] = true;
        if(isAllVis(n)){
            printf("Sorted sequence determined after %d relations: %s.\n",curNum,ss.c_str());
            return;
        }
        for(int i = 0; i < Edge[v].size(); i++){
            int u = Edge[v][i];
            if(--inde[u] == 0){
                q.push(u);
            }
        }
    }
    if(curNum < n) ;
}

int main(){
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    while(n != 0){
        tol = 0;
        for(int i = 0; i < n; i++){
            Edge[i].clear();
        }
        memset(inde,0,sizeof(inde));
        memset(vis,0,sizeof(vis));
        char c[10];
        for(int i = 0; i < m; i++){
            scanf("%s",c);
            addEdge(c[0]-'A',c[2]-'A'); 
        }
        topSort(n);
        scanf("%d%d",&n,&m);
    }
    return 0;
}