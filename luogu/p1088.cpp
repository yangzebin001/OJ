/*
 * @Date: 2020-02-13 22:10:05
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-13 22:12:12
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int arr[10010];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >>arr[i];
    for(int i = 0; i < m; i++){
        next_permutation(arr,arr+n);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}