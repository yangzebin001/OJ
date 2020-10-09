/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 09:38:46 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 09:46:24
 */

#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 5010;

struct e{
    int l,w;
}p[MAXN];
int dp[MAXN], len;

bool cmp(e &a, e &b){
    if(a.l == b.l) return a.w > b.w;
    return a.l > b.l;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].l >> p[i].w;
    }
    sort(p,p+n, cmp);
    int ans = 0;
    //对w求最长上升子序列
    for(int i = 0; i < n; i++){
        int j = lower_bound(dp, dp+len, p[i].w) - dp;
        if(j == len) dp[len++] = p[i].w;
        else dp[j] = p[i].w;
    }
    cout << len;
    return 0;
}