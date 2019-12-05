#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 110;
int arr[MAXN][MAXN],dp[MAXN][MAXN];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j])
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            ans = max(ans,dp[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}