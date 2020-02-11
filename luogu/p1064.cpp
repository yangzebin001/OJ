/*
 * @Date: 2020-01-21 19:03:07
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-21 19:19:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> PII;

int n,m,dp[32010];
vector<PII> servent[65];
PII master[65];
int main(){
    freopen("in.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 1; i <= n; i++){
        int v,w,kind;
        scanf("%d%d%d",&v,&w,&kind);
        if(kind == 0){
            master[i] = make_pair(v,w*v);
        }else{
            servent[kind].push_back(make_pair(v,w*v));
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            for(int t = 0; t < 1<<servent[i].size(); t++){
                int v = master[i].first,w = master[i].second;
                for(int k = 0; k < servent[i].size(); k++){
                    if(t>>k & 1){
                        v += servent[i][k].first;
                        w += servent[i][k].second;
                    }
                }
                if(v <= j){
                    dp[j] = max(dp[j],dp[j-v]+w);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}