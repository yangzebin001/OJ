/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 18:17:43 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 19:51:58
 */
#include<bits/stdc++.h>

using namespace std;
const long long target = 59084709587505;
bool check(int i, int j, int k){
    long long sum = 1;
    while(i--){
        sum *= 3;
        if(sum >= target) return false;
    }
    while(j--){
        sum *= 5;
        if(sum >= target) return false;
    }
    while(k--){
        sum *= 7;
        if(sum >= target) return false;
    }
    return true;
}

int main(){
    int ans = 0;
    for(int i = 0; i <= 31; i++){
        for(int j = 0; j <= 20; j++){
            for(int k = 0; k <= 17; k++){
                if(check(i,j,k)) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}