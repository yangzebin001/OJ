/*
 * @Date: 2020-01-19 20:56:58
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-19 20:59:24
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int p[101];
int main(){
    int n,sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        sum += p[i];
    }
    sum /= n;
    for(int i = 0; i < n; i++){
        p[i] = p[i]-sum;
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(p[i] == 0) continue;
        else p[i+1] += p[i],ans++;
    }
    cout << ans;
    return 0;
}