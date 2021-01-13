#include<bits/stdc++.h>

using namespace std;

int main(){
    long long ans = 0;
    int a,b,c;
    cin >> a >> b >> c;
    int bb = min(a,b);
    ans += bb; a -= bb; b -= bb;
    int cc = min(a,c);
    ans += cc; a -= cc; c -= cc;
    ans += c/2;
    cout << ans;
    return 0;
}