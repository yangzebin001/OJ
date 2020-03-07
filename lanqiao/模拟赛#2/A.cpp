/*
 * @Date: 2020-02-22 12:54:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 13:39:13
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
bool check(string a){
    string b;
    for(int i = 0; i < 6; i++){
        if(a[i] == '0' || a[i] == '1' || a[i] == '8'){
            b = a[i] + b;
        }else if(a[i] == '6'){
            b = '9' + b;
        }else if(a[i] == '9'){
            b = '6' + b;
        }else{
            return false;
        }
    }
    if(a == b)
        cout << a <<" "<<  b << endl;
    return a == b;
}
int main(){
    // int cnt = 0;
    // string A;
    // for(char a = '0'; a <= '9'; a++){
    // for(char b = '0'; b <= '9'; b++){
    // for(char c = '0'; c <= '9'; c++){
    // for(char d = '0'; d <= '9'; d++){
    // for(char e = '0'; e <= '9'; e++){
    // for(char f = '0'; f <= '9'; f++){
    //     A += a;A += b;A += c;A += d;A += e;A += f;
    //     cnt += check(A);
    //     // cout << A << endl;
    //     A="";
    // }
    // }
    // }
    // }
    // }
    // }
    // cout << cnt <<endl;
    cout << 125 <<endl;
    return 0;
}