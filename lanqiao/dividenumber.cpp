#include<bits/stdc++.h>

using namespace std;

bool check(int x){
    while(x){
        if(x%10 == 2 || x%10 == 4) return false;
        x/=10;
    }
    return true;
}

int main(){
    int ans = 0;
    for(int i = 1; i <= 2019 /3; i++){
        for(int j = i+1; j <= 2019; j++){
            int k = 2019-i-j;
            if(k <= j) continue;
            if(check(i) && check(j) && check(k)) ans++;
        }
    }
    cout << ans;
    return 0;
}