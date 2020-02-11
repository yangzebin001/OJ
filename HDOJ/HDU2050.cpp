#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[10010];
int main(){
    dp[0] = 1;
    for(int i = 1; i <= 10000; i++){
        dp[i] = dp[i-1]+4*(i-1)+1;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
}