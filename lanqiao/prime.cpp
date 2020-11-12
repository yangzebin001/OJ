/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-14 17:31:40 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-14 17:36:07
 */
#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
long long ans[3000];
bool isprime(int x){
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}
int main(){
    long long i = 2;
    while(cnt < 2019){
        if(isprime(i)) ans[cnt++] = i;
        i++;
    }
    cout << ans[cnt-1];
    return 0;
}