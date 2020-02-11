/*
 * @Date: 2020-01-23 22:38:26
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 22:44:14
 */
#include<iostream>
#include<cstdio>
using namespace std;
char toc(int a){
    if(a <= 9) return '0'+a;
    else return 'A'+(a-10);
}
void ton(int n){
    string a;
    while(n){
        a = toc(n%13) + a;
        n/=13;
    }
    
    while(a.size() < 2) a = '0'+a;
    cout <<a;
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout <<"#";
    ton(a);
    ton(b);
    ton(c);
    return 0;
}