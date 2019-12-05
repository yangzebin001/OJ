/*
 * @Date: 2019-11-16 10:31:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-16 10:37:57
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    string a,b;
    while(cin >> a >> b){
        
        int dp[a.size()+10][b.size()+10];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= a.size(); i++){
            for(int j = 1; j <= b.size(); j++){
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
    
    return 0;
}