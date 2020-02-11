/*
 * @Date: 2020-01-23 15:56:06
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 17:37:06
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
using namespace std;
int dp[300][50]; //表示前i个字符分割为k段所用单词的最大值。
string words[10];
int sum[300][300];

string s = "0";
int p,k,t,n;
bool check(int l, int r){
    string x = s.substr(l,r-l+1);
    for(int i = 0; i < t; i++){
        if(x.find(words[i]) == 0) return true;
    }
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> p >> k;
    while(p--){
        string a;
        cin >> a;
        s += a;
    }
    n = s.size()-1;
    cin >> t;
    for(int i = 0; i < t; i++) cin >> words[i];

    //预处理sum sum[i][j] 为从i到j的单词数
    //sum[i][j] = sum[i+1][j] 有没有以S[i]开头的单词
    for(int i = n; i >= 1; i--){
        for(int j = i; j >= 1; j--){
            sum[j][i] = sum[j+1][i];
            if(check(j,i)) sum[j][i]++;
        }
    }
    
    
    for(int i = 1; i <= s.size(); i++) dp[i][1] = sum[1][i];
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= min((int)s.size(),k); j++){
            //dp[i][j] = max(以c开始，j-1串构成的最大单词数)
            // 前c个字符组成的j-1个串
            // 只有j个字符才能构成j个子串，所以j从c开始
            for(int c = j; c < i; c++){
                dp[i][j] = max(dp[i][j],dp[c][j-1]+sum[c+1][i]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}