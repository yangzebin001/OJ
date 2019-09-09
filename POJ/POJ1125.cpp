/*
 * @Date: 2019-08-26 15:27:47
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 15:58:59
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 120;
const int INF = 0x3f3f3f3f;
int M[MAXN][MAXN];

void floyd(int n){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(M[i][j] > M[i][k]+M[k][j]) M[i][j] = M[i][k]+M[k][j];
}

int main(){
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n) && n){
        memset(M,INF,sizeof(M));
        for(int i = 1; i <= n; i++){
            int c;
            scanf("%d",&c);
            for(int j = 0; j < c; j++){
                int a,w;
                scanf("%d%d",&a,&w);
                M[i][a] = w;
            }
        }
        floyd(n);
        int anslen = INF,ansi;
        int flag = 0;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++)
        //         printf("%d ",M[i][j]);
        //     printf("\n");
        // }
        for(int i = 1; i <= n; i++){
            int curlen = 0;
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                curlen = max(curlen,M[i][j]);
            }
            // if(curlen == INF) flag = 1;
            if(anslen > curlen){
                anslen = min(curlen,anslen);   
                ansi = i;
            }
        }
        if(anslen == INF) printf("disjoint\n");
        else printf("%d %d\n",ansi,anslen);
    }
    return 0;
}