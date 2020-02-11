#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2010;
int one[MAXN],two[MAXN];
int dp[MAXN];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(one,0,sizeof(one));
        memset(two,0,sizeof(two));
        memset(dp,0,sizeof(dp));
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> one[i];
        for(int i = 2; i <= n; i++) cin >> two[i];
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + one[i];
            if(i >=2 ) dp[i] = min(dp[i],two[i]+dp[i-2]);
        }
        int ans = dp[n];
        int second = ans%60;
        int minute = ans/60%60;
        int hour = ans/3600;
        if(hour + 8 > 12){
            printf("%02d:%02d:%02d pm\n",hour+8-12,minute,second);
        }else{
            printf("%02d:%02d:%02d am\n",hour+8,minute,second);
        }
    }
    return 0;
}