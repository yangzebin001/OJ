/*
 * @Date: 2019-11-14 19:54:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-14 20:25:19
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 4e6;
int dp[MAXN];
unordered_map<int,vector<int> > M;
int main(){
    freopen("in.txt","r",stdin);
    int N;
    int end = 0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a > b) swap(a,b);
        M[b].push_back(a);
        end = max(end,b);
    }
    for(int i = 1; i <= end; i++){
        dp[i] = dp[i-1];
        if(M.find(i) != M.end()){
            for(int j = 0; j < M[i].size(); j++){
                int t = M[i][j];
                dp[i] = max(dp[i],dp[t-1]+(i-t+1));
            }
        }
    }
    // for(int i = 1; i <= end; i++){
    //     printf("%d ",dp[i]);
    // }
    printf("%d",dp[end]);

    return 0;
}