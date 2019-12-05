/*
 * @Date: 2019-11-19 11:09:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 11:30:57
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1e6+10;
struct node{
    int s,m;
    node(){};
    node(int _s, int _m){
        s = _s;
        m = _m;
    }
};
int dp[MAXN];
vector<node> e[MAXN];
int N,M,R;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&M,&R);
    for(int i = 0; i < M; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[b].push_back(node(a,c));
    }
    for(int i = 0; i <= N; i++){
        if(i>0){
            dp[i] = dp[i-1];
        }
        if(e[i].size()){
            for(int j = 0; j < e[i].size(); j++){
                if(e[i][j].s-R >= 0)
                    dp[i] = max(dp[e[i][j].s-R]+ e[i][j].m,dp[i]);
                else if(i>0){
                    dp[i] = max(dp[i-1],e[i][j].m);
                }
            }
        }
    }
    printf("%d",dp[N]);
    return 0;
}