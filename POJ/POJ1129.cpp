/*
 * @Date: 2019-08-26 08:44:01
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 15:04:06
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int MAXN = 30;
int T;

vector<int> M[MAXN];
int color[MAXN];

int f = 0;
int minnum;

bool isSuccess(int n){
    for(int i = 0; i < M[n].size(); i++){
        if(color[M[n][i]] == 0) return false;        
    }
    return true;
}

void dfs(int n){
    if(color[n]) return;
    set<int> s;
    for(int i = 0; i < M[n].size(); i++){
        s.insert(color[M[n][i]]);    
    }
    for(int i = 1; i <= 26; i++){
        if(!s.count(i)){
            color[n] = i;
            
            for(int j = 0; j < M[n].size(); j++){
                if(!color[M[n][j]]) {
                    dfs(M[n][j]);
                }
            }
            break;
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d",&T) && T){
        minnum = 0;
        for(int i = 0; i < T; i++){
            M[i].clear();
        }
        memset(color,0,sizeof(color));
        char s[1000];
        for(int i = 0; i < T; i++){
            scanf("%s",s);
            int now = s[0]-'A';
            for(int i = 2; i < strlen(s); i++){
                M[now].push_back(s[i]-'A');
                // printf("%d ",s[i]-'A');
            }
        }
        for(int i = 0; i < T; i++){
            if(!color[i]) dfs(i);
        }
        for(int i = 0; i < T; i++){
            minnum = max(minnum,color[i]);
        }
        if(minnum <= 1)
            printf("%d channel needed.\n",minnum);
        else
            printf("%d channels needed.\n",minnum);

    }
    
    return 0;
}