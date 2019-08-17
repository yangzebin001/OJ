#include<iostream>
#define LL long long
using namespace std;

LL fastPow(LL a, LL b, LL p){
    LL ans = 1%p;
    while(b){
        if(b&1) ans = ans * a % p;
        b >>= 1;
        a = a * a %p;
    }
    return ans;
}

int main(){
    // freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    while(T--){
        LL M,a,b,ans = 0;
        cin >> M;
        int t;
        cin >> t;
        while(t--){
            cin >> a >> b;
            ans = (ans + fastPow(a,b,M)) % M;
        }
        cout << ans << endl;
    }
    return 0;
}