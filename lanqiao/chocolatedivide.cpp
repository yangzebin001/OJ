/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 17:21:08 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 17:48:57
 */
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n,k;
int h[MAXN],w[MAXN];

int check(int c){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += (h[i]/c)*(w[i]/c);
    }
    return cnt >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i] >> w[i];
    int l = 0, r = 100001;
    while(l < r){
        int mid = l+r+1>>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l;
    return 0;
}