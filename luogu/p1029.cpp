#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}
int n,m,ans;
int main(){
    cin >> m >> n;
    if(n == m) ans--;
    n *= m;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0 && gcd(i, n/i) == m) ans += 2;
    }
    cout << ans;
    return 0;
}