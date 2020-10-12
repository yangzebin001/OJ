/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 21:55:22 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-12 21:55:22 
 */
#include<bits/stdc++.h>

using namespace std;
long long a[100010];

long long gcd(long long a, long long b){
    return b ? gcd(b, a%b) : a;
}
int n;
int main(){
    cin >> n;
    long long ca;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    ca = a[1]-a[0];
    for(int i = 2; i < n; i++){
        ca = gcd(ca, a[i] - a[i-1]);
    }
    if(ca == 0) cout << n;
    else cout << (a[n-1] - a[0]) / ca + 1 << endl;
    return 0;
}