/*
 * @Date: 2020-01-22 15:47:14
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 16:24:36
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string words[610];
int dp[310];
int main(){
    int n,m;
    string s;
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++) cin >> words[i];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(words[j][0] == s[i]){
                int r = i;
                int wr = 0;
                while(r < m){
                    if(words[j][wr] == s[r]){
                        wr++;
                    }
                    if(wr == words[j].size()){
                        dp[r+1] = max(dp[r+1],dp[i]+wr);
                    }
                    r++;
                }
            }
        }
    }
    cout << m-dp[m] << endl;
    return 0;
}