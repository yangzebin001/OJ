/*
 * @Date: 2020-02-11 18:56:30
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 19:52:50
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int arr[100010];
//判断是否能有小于m个区间并使每个区间的数都不大于mid。
//如果有少于m个区间，说明给定的mid值大了，需要缩小。
bool check(int mid){
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(sum + arr[i] <= mid) sum += arr[i];
        else{
            sum = arr[i];
            cnt++;
        }
    }
    if(sum) cnt++;
    return cnt <= m;
}
int main(){
    cin >> n >> m;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        maxn = max(arr[i],maxn);
    }
    int l = maxn, r = 1e9+10;
    while(l < r){
        int mid = l+r>>1;
        //最大值最小化
        //要缩小mid说明划分的区间数小了，缩小单位内的和也就是增加区间数。
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l;

    return 0;
}