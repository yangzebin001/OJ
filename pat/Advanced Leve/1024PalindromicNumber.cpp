/*
 * @Date: 2020-01-23 22:46:59
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 23:13:17
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool isp(string s){
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}
int ton(char i){
    return i-'0';
}
string add(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.size() > b.size()) return add(b,a);
    string ans = "";
    int t = 0;
    int i;
    for(i = 0; i < a.size(); i++){
        ans += '0' + ((t +ton(a[i]) + ton(b[i]))%10);
        t = (t +ton(a[i]) + ton(b[i]))/10;
    }
    
    while(i < b.size()){
        ans += '0' + (t + ton(b[i]))%10;
        t = (t + ton(b[i]))/10;
        i++;
    }
    if(t) ans += '1';
    reverse(ans.begin(),ans.end());
    return ans;
}
string fz(string n){
    reverse(n.begin(),n.end());
    return n;
}
int main(){
    string a;
    int k;
    cin >> a >> k;
    int t = 1;
    if(isp(a)){
        cout << a << endl << t-1 << endl;
        return 0;
    }
    for(; t <= k; t++){
        string c = fz(a);
        a = add(c,a);
        if(isp(a)){
            cout << a << endl << t << endl;
            return 0;
        }
    }
    cout << a << endl << t-1 << endl;
    return 0;
}