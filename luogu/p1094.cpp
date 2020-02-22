/*
 * @Date: 2020-02-12 14:45:32
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 14:48:48
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int arr[30010];
int main(){
    int n,m;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int cnt = 0;
    int l = 0, r = n-1;
    while(l < r){
        if(arr[l]+arr[r] > m){
            r--;
        }else{
            l++,r--;
        }
            cnt++;
    }
    if(l == r) cnt++;
    cout << cnt;
    return 0;
}