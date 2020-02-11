/*
 * @Date: 2020-02-07 13:53:07
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-07 16:50:45
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
bool isprime(int x){
    if(x == 1 || x == 2) return true;
    for(int i = 2; i * i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}
int cntnum(int x){
    if(x == 1) return 0;
    if(isprime(x)) return 1;
    set<int> s;
    while(!isprime(x)){
        for(int i = 2; i*i <= x; i++){
            if(x%i == 0){
                s.insert(i);
                x/=i;
                break;
            }
        }
    }
    s.insert(x);
    return s.size();
}
bool check(int x){
    while(x){
        if(x%10 == 5) return false;
        x/=10;
    }
    return true;
}
int main(){
    // int cnt = 0;
    // for(int i = 1; i <= 2020; i++){
    //     if(check(i)){
    //         int c = cntnum(i);
    //         cnt += c;
    //     }
    // }
    // cout << cnt << endl;
    cout << 3257 << endl;
    return 0;
}