/*
 * @Date: 2019-08-26 16:42:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 17:53:27
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;
int N;
map<string,int> m;
double G[MAXN][MAXN];

bool floyd(int N){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(G[i][j] < G[i][k] * G[k][j])
                    G[i][j] = G[i][k] * G[k][j];

    for(int i = 0; i < N; i++) if(G[i][i] > 1) return true;
    return false;
}


int main(){
    freopen("in.txt","r",stdin);
    int ca = 1;
    while(scanf("%d",&N) && N){
        m.clear();
        fill_n(G[0],MAXN*MAXN,0);
        for(int i = 0; i < N; i++) G[i][i] = 1; 

        for(int i = 0; i < N; i++){
            char c[1000];
            scanf("%s",c);
            m[string(c)] = i;
        }
        int t;
        scanf("%d",&t);
        for(int i = 0; i < t; i++){
            char c1[1000],c2[1000];
            double d;
            scanf("%s%lf%s",c1,&d,c2);
            G[m[string(c1)]][m[string(c2)]] = d;
        }
        printf("Case %d: ",ca++);
        if(floyd(N)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}