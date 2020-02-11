/*
 * @Date: 2020-02-08 20:29:14
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 20:51:11
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL quick_mi(LL n, LL m, LL p){
    LL ans = 1%p;
    while(m){
        if(m&1) ans = ans*n%p;
        n = n*n%p;
        m>>=1;
    }
    return ans;
}
int main(){
    LL n,m,p;
    cin >> n >> m >> p;
    
    printf("%lld^%lld mod %lld=%lld\n",n,m,p,quick_mi(n,m,p));
    return 0;
}