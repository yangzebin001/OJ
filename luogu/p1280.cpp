#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1e4+10;

int dp[MAXN],N,K,a,b;
vector<int> points[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0; i < K; i++){
        scanf("%d%d",&a,&b);
        points[a].push_back(a+b);
    }
    for(int i = N; i >= 1; i--){
        if(points[i].size()){
            for(int j = 0; j < points[i].size(); j++){
                dp[i] = max(dp[i],dp[points[i][j]]);
            }
        }else{
            dp[i] = dp[i+1]+1;
        }
        // printf("%d ",dp[i]);
    }
    printf("%d",dp[1]);
    return 0;
}