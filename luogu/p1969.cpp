/*
 * @Date: 2020-02-10 14:47:53
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 15:04:17
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[100010],b[100010];
int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = arr[i]-arr[i-1]; 
        ans += max(0,b[i]);
    }
    cout << ans;
    return 0;
}