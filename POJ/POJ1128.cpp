#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

char M[50][50];
char B[50][50];
int dot[30][4];
int vis[50];
vector<string> vs;

int h,w;

bool isRight(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(M[i][j] != B[i][j]) return false;
        }
    }
    return true;
}


bool dye(char c,int f){
    int x1 = dot[c-'A'][0];
    int y1 = dot[c-'A'][1];
    int x2 = dot[c-'A'][2];
    int y2 = dot[c-'A'][3];
    for(int i = x1; i <= x2; i++){
        if(i == x1 || i == x2){
            for(int j = y1; j <= y2; j++){
                if(B[i][j] == M[i][j]) return false;
                B[i][j] = c;
            }
        }else{
            if(B[i][y1] == M[i][y1]) return false;
                B[i][y1] = c;
            if(B[i][y2] == M[i][y2]) return false;
                B[i][y2] = c;
        }
    }
    return true;
}

void dfs(string s,int u,int &ith){
    if(u == s.size()){
        // for(int i = 0; i < h; i++){
        //     for(int j = 0; j < w; j++){
        //         printf("%c",B[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        if(isRight()){
            printf("%s\n",s.c_str());
        }
        return;
    }
    if(dye(s[u],ith)){

        dfs(s,u+1,++ith);
    }
}

void pailie(string s,string a, int u){
    if(u == s.size()){
        vs.push_back(a);
        return;
    }
    for(int i = 0; i < s.size(); i++){
        if(!vis[s[i]-'A']){
            vis[s[i]-'A'] = 1;
            a += s[i];
            pailie(s,a,u+1);
            a.erase(a.size()-1);
            vis[s[i]-'A'] = 0;
        }
    }
}

bool judge(char c){
    int x1 = dot[c-'A'][0];
    int y1 = dot[c-'A'][1];
    int x2 = dot[c-'A'][2];
    int y2 = dot[c-'A'][3];
    for(int i = x1; i <= x2; i++){
        if(i == x1 || i == x2){
            for(int j = y1; j <= y2; j++){
                if(c != M[i][j]) return false;
            }
        }else{
            if(c != M[i][y1]) return false;
            if(c != M[i][y2]) return false;
        }
    }
    return true;
}

void init(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            B[i][j] = '.';
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&h,&w) != EOF){
    memset(dot,-1,sizeof(dot));
    memset(M,0,sizeof(M));
    memset(vis,0,sizeof(vis));
    vs.clear();
    for(int i = 0; i < h; i++){
        scanf("%s",M[i]);
        for(int j = 0; j < w; j++){
        	if(M[i][j] == '.')continue;
            if(dot[M[i][j]-'A'][0] == -1 && dot[M[i][j]-'A'][1] == -1){
                dot[M[i][j]-'A'][0] = i;
                dot[M[i][j]-'A'][1] = j;
            }else{
                dot[M[i][j]-'A'][2] = i;
                dot[M[i][j]-'A'][3] = j;
            }
        }
    }
    string s = "";
    char startwith;
    for(int i = 0; i < 26; i++){
        if(dot[i][0] != -1) s += 'A'+i;
    }
    for(int i = 0; i < s.size(); i++){
        if(judge(s[i])){
            startwith = s[i];
            break;
        }
    }
    // printf("%c\n",startwith);
	// printf("%s",s.c_str());
    pailie(s,"",0);
    for(int i = 0; i < vs.size(); i++){
        if(vs[i][vs[i].size()-1] == startwith){
            // printf("%s\n",vs[i].c_str());
            init();
            int a = 0;
            dfs(vs[i],0,a);
        }
    }
    }
    return 0;
}