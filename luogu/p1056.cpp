/*
 * @Date: 2019-08-31 11:32:14
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-31 16:03:38
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int M,N,K,L,D;
const int MAXN = 1005;
int x[MAXN],y[MAXN],xt[MAXN],yt[MAXN];


int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
    int x1,y1,x2,y2;
    for(int i = 0; i < D; i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1 == x2){
            y[min(y1,y2)]++;
        }else{
            x[min(x1,x2)]++;
        }
    }
    for(int i = 1; i <= K; i++){
        int p = -1;
        int Max = 0;
        for(int j = 1; j <= M; j++){
            if(x[j] > Max){
                Max = x[j];
                p = j;
            }
        }
        xt[p]++;
        x[p] = 0;
    }

    for(int i = 1; i <= L; i++){
        int p = -1;
        int Max = 0;
        for(int j = 1; j <= N; j++){
            if(y[j] > Max){
                Max = y[j];
                p = j;
            }
        }
        yt[p]++;
        y[p] = 0;
    }
    for(int i = 1; i <= M; i++){
        if(xt[i]) printf("%d ",i);
    }
    printf("\n");
    for(int i = 1; i <= N; i++){
        if(yt[i]) printf("%d ",i);
    }
    return 0;
}