/*
 * @Date: 2020-01-22 22:35:47
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 22:59:11
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void solve(){
    
    long long a,b,c,n;
    cin >> a >> b >> c >> n;
    int t = max(a,max(b,c));
    int rest = (t-a)+(t-b)+t-c;
    n -= rest;
    if(n >= 0 && n%3 == 0) {
        printf("YES\n");
    }else{
        printf("NO\n");

    }
    
}
int main(){
    // freopen("in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}