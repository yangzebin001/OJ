#include<iostream>

using namespace std;
long long n,v,m,a,ans;
int main(){
    cin >> n >> v >> m >> a;
    long long j = 0;
    for(long long i = 1; i <= n; i++, j++){
        if(j == m) v += a, j=0;
        // cout << v << endl;
        ans += v;
    }
    cout << ans << endl;
    return 0;
}