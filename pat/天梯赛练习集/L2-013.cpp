/*
 * @Date: 2019-11-11 14:58:56
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-11 15:22:38
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int MAXN = 550;
int MAP[MAXN][MAXN];
int vis[MAXN];
int V[MAXN];

int N,M,K;

void dfs(int t){
    V[t] = 1;
    for(int i = 0; i < N; i++){
        if(MAP[t][i] && !V[i]){
            dfs(i);
        }
    }
}

int compentsnum(){
    memset(V,0,sizeof(V));
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(vis[i] != -1 && V[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    int a,b;
    for(int i = 0; i < M; i++){
        scanf("%d%d",&a,&b);
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }
    scanf("%d",&K);
    
    int original_K = compentsnum();
    for(int i = 0; i < K; i++){
        scanf("%d",&a);
        int flag = 1;
        for(int j = 0; j < N; j++){
            if(MAP[a][j] || MAP[j][a]) flag = 0;
            MAP[a][j] = 0;
            MAP[j][a] = 0;
        }
        vis[a] = -1;
        if(flag){
            original_K--;
            printf("City %d is lost.\n",a);
            if(!original_K){
                printf("Game Over.\n");
                return 0;
            }
            continue;
        }
        int cur_K = compentsnum();
        if(cur_K == original_K){
            printf("City %d is lost.\n",a);
        }else{
            printf("Red Alert: City %d is lost!\n",a);
        }
        // printf("%d\n",cur_K);
        original_K = cur_K;
        // if(original)
    }
    return 0;
}