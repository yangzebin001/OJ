/*
 * @Date: 2019-09-20 21:43:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-20 21:46:51
 */
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s;
int main(){
    cin >> s;
    int ans = 0;
    int pcnt = 0;
    int acnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'P') pcnt++;
        if(s[i] == 'A') acnt += pcnt;
        if(s[i] == 'T') ans = (ans + acnt) %1000000007;
    }
    printf("%d",ans);
    return 0;
}