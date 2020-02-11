/*
 * @Date: 2020-02-11 19:56:09
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 20:10:53
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[100010];

int n,m;

bool check(int mid){
    int cnt = 1;
    int cur = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - cur >= mid){
            cur = arr[i];
            cnt++;
        }
    }
    return cnt >= m;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int l = 0, r = arr[n-1]-arr[0];
    while(l < r){
        int mid = l+r+1>>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l;
    return 0;
}