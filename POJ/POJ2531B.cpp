#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 30;
const int INF = 0x3f3f3f3f;

int n;
int M[MAXN][MAXN];
int ans;
int curans;
int vis[MAXN];

void dfs(int x,int sum){
    if(x == n){
        ans = max(sum,ans);
        return;
    }
    dfs(x+1,sum);
    vis[x] = 1;
    int t = 0;
    for(int i = 0; i <n; i++){
        if(!vis[i]){
            t += M[i][x];
        }else{
            t -= M[i][x];
        }
    }
    dfs(x+1,sum+t);
    vis[x] = 0;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&M[i][j]);
        }
    }
    dfs(0,0);
    printf("%d",ans);
    return 0;
}