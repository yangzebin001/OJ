/*
 * @Date: 2020-02-07 14:42:27
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 10:41:57
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 1e6;
int t[20];
bool check(int x){
    int tt = 0;
    while(x){
        t[tt] = x%10;
        x /= 10;
        tt++;
    }
    if(tt%2) return false;
    for(int i = 0, j = tt/2; i < tt/2; i++,j++){
        if(t[i] != t[j]) return false;
    }
    return true;
}
int main(){
    long long cnt= 0;
    long long n;
    scanf("%lld",&n);
    for(int i = 10; i <= n; i++){
        if(check(i)) cnt += i;
    }
    printf("%lld",cnt);
    return 0;
}