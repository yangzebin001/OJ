/*
 * @Date: 2019-09-10 16:41:54
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-10 16:45:55
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[10001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << a[n>>1];
    return 0;
}