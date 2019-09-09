/*
 * @Date: 2019-08-30 09:05:46
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-30 09:54:17
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXN = 200;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];
int N,M;
int main(){
    freopen("in.txt","r",stdin);
    memset(G,0,sizeof(G));
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        //生成a赢b的关系图
        G[a][b] = 1;
    }
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                //B>C，A>B，说明A>C
                if(G[i][k] && G[k][j]) G[i][j] = 1;

    /*
    只有当一个点与其他个点都有联系（或赢或输）,才可以确定该点
    */
    int ans = 0;
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++){
        // 又因为该题有唯一的赢输判定，所以与其他各点都有联系可以直接表示为加的和为N-1
        // 否则只能一一判定当前点与其他个点的关系。
            sum = sum + G[i][j] + G[j][i];
        }
        if(sum == N-1) ans++;
    }
    printf("%d\n",ans);

    return 0;
}