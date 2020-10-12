/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 15:05:50 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-12 15:05:50 
 */
#include<bits/stdc++.h>

using namespace std;
vector<long long> field[3030];
long long a[100100];
long long n,k,x,ans;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i < n; i++) {
        field[a[i]%k].push_back(a[i]);
    }
    for(int i = 0; i < k; i++){
        if(!field[i].size()) continue;
        long long a = field[i].back();
        field[i].pop_back();
        for(int j = 0; j < k; j++){
            if(!field[j].size()) continue;
            long long b = field[j].back();
            field[j].pop_back();
            int rest = k-(i+j)%k; //没想到i,j都为空的情况 坑了我一下午 =。=
            if(rest < 0 || !field[rest].size()) { field[j].push_back(b); continue;}
            ans = max(ans,a+b+field[rest].back());
            field[j].push_back(b);
        }
        field[i].push_back(a);
    }
    cout << ans;
    return 0;
}