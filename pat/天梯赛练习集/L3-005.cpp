/*
 * @Date: 2020-02-19 22:10:34
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-19 22:54:54
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e3+20;
int dp[MAXN][MAXN];
const int INF = 0x3f3f3f3f;
int n,m,k,d;
char s1[10],s2[10];
int tot = 0;
int ton(char s1[10]){
    int len = strlen(s1);
    int num = 0;
    int i = 0;
    int f = 0;
    if(s1[0] == 'G') f = 1,i++;
    for(; i < len; i++){
        num = num *10 + (s1[i]-'0');
    }
    if(f) num += n;
    return num;
}
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    memset(dp,INF,sizeof dp);
    // for(int i = 0; i < MAXN; i++){
    //     for(int j = 0; j < MAXN; j++){
    //         dp[i][j] = INF;
    //     }
    // }
    scanf("%d%d%d%d",&n,&m,&k,&d);
    tot = n+m;
    int dd;
    for(int i = 0; i < k; i++){
        scanf("%s%s%d",s1,s2,&dd);
        int a = ton(s1), b = ton(s2);
        dp[a][b] = dd;
        dp[b][a] = dd;
    }
    for(int k = 1; k <= tot; k++){
        for(int i = 1; i <= tot; i++){
            for(int j = 1; j <= tot; j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int idx = 0;
    int mind = 0;
    double sumd = 0;
    for(int i = n+1; i <= tot; i++){
        int curmind = INF;
        int f = 0;
        double cursumd = 0;
        for(int j = 1; j <= n; j++){
            if(dp[i][j] > d){
                f = 1;
                break;
            }
            curmind = min(curmind,dp[i][j]);
            cursumd += dp[i][j]*1.0;
        }
        if(f) continue;
        if(curmind > mind || (curmind == mind && cursumd < sumd)){
            mind = curmind;
            idx = i;
            sumd = cursumd;
        }
    }
    if(idx == 0){
        printf("No Solution\n");
    }else{
        printf("G%d\n%.1f %.1f",idx-n,mind*1.0,sumd/n);
    }

    return 0;
}