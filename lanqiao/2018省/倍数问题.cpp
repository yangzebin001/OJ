/*
 * @Date: 2020-02-07 12:38:55
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-09 12:49:49
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int n,k;
long long arr[100010];
stack<long long> km[1010];
void add(long long x){
    long long c = x%k;
    km[c].push(x);
}
int main(){
    long long ans = 0;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        add(arr[i]);
    }
    for(int i = 0; i < k; i++){
        if(km[i].empty()) continue;
        long long  x = km[i].top();km[i].pop();
        for(int j = 0; j < k; j++){
            if(km[j].empty()) continue;
            long long y = km[j].top();km[j].pop();
            int l = (2*k-i-j)%k;
            if(km[l].empty()){
                km[j].push(y);
                continue;
            }
            long long z = km[l].top();km[l].pop();
            ans = max(ans,x+y+z);
            km[l].push(z);
            km[j].push(y);
        }
        km[i].push(x);
    }
    cout << ans;
    return 0;
}