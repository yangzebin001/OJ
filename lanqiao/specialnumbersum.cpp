#include<bits/stdc++.h>

using namespace std;

bool check(int x){
    while(x){
        int t = x % 10;
        if(t == 2 || t == 1 || t == 0 || t == 9) return true;
        x /= 10;
    }
    return false;
}

int main(){
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) if(check(i)) ans += i;
    cout << ans;
    return 0;
}