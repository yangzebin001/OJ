/*
 * @Date: 2019-10-12 15:18:12
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-12 15:26:41
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
using namespace std;
typedef pair<long long,string> P;
set<P> s1,s2;
int main(){
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        string c,s,e;
        cin >> c >> s >> e;
        long long ss = 0,ee = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] >= '0' && s[j] <= '9'){
                ss = ss*10 + s[j]-'0';
            }
        }
        for(int j = 0; j < e.size(); j++){
            if(e[j] >= '0' && e[j] <= '9'){
                ee = ee*10 + e[j]-'0';
            }
        }
        s1.insert(P(ss,c));
        s2.insert(P(-ee,c));
    }
    cout << s1.begin()->second << " " << s2.begin()->second;
    return 0;
}