/*
 * @Date: 2020-02-15 20:56:18
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-15 20:56:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string mul1(string a, int b,int addpos){
    int t = 0,i = 0;
    string c;
    while(i < a.size()){
        t += (a[i]-'0')*b;
        c += '0'+(t%10);
        t/=10;
        i++;
    }
    while(t){
        c += '0'+(t%10);
        t/=10;
    }
    while(addpos--) c = '0'+c;
    return c;
}
string mul(string a, string b){
    string c;
    vector<string> v;
    int maxlen = 0;
    for(int i = 0; i < b.size(); i++){
        v.push_back(mul1(a,b[i]-'0',i));
        maxlen = max(maxlen,(int)v.back().size());
    }
    int t = 0;
    for(int j = 0; j < maxlen; j++){
        for(int i = 0; i < v.size(); i++){
            if(j < v[i].size()){
                t += (v[i][j]-'0');
            }
        }
        c += '0'+(t%10);
        t /= 10;
    }
    while(t){
        c += '0'+(t%10);
        t /= 10;
    }
    return c;
}
string fastpow(string a, int b){
    string ans = "1";
    string x = a;
    while(b){
        if(b&1) ans = mul(ans,x);
        x = mul(x,x);
        b>>=1;
    }
    return ans;
}
int main(){
    string a,b,c;
    cin >> a;
    reverse(a.begin(),a.end());
    c = fastpow(a,2);
    reverse(c.begin(),c.end());
    cout << c;
    
    return 0;
}