/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-13 14:16:20 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-13 14:17:07
 */
#include<bits/stdc++.h>

using namespace std;
int a[100010];
int b[100010];
int c[100010];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    long long ans = 0;
    for(int i = 0, j = 0, k = 0; j < n; j++){
        while(i < n && a[i] < b[j]) i++;
        while(k < n && c[k] <= b[j]) k++;
        ans += (long long)i*(n-k);
    }
    cout << ans;
    return 0;
}