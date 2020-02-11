/*
 * @Date: 2020-02-10 21:09:29
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 22:14:15
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string dp[5050];
string add(string A,string B){
    int t = 0,i;
    if(A.size() > B.size()) return add(B,A);
    string C;
    for(i = 0; i < A.size(); i++){
        t += (A[i]-'0') + (B[i]-'0');
        C += ('0'+(t%10));
        t /= 10;
    }
    while(i < B.size()){
        t += (B[i]-'0');
        C += ('0'+(t%10));
        t /= 10; 
        i++;
    } 
    if(t) C += "1";
    return C;
}
int main(){
    dp[0] = "0";
    dp[1] = "1";
    dp[2] = "2";
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++){
        dp[i] = add(dp[i-1],dp[i-2]);
    }
    reverse(dp[n].begin(),dp[n].end());
    cout << dp[n];
    return 0;
}