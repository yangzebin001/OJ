/*
 * @Date: 2019-09-08 22:20:55
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-09 15:46:04
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string, int> m;

void cal(string a,int k){
    for(int i = 0; i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            string t = a.substr(i, j-i+1);
            if(m[t] == k) m[t]++;
        }
    }
}
int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        m.clear();
        int t,j;
        cin >> t;
        string q;
        for(j = 0; j < t; j++){
            cin >> q;
            cal(q,j);
        }
        map<string, int>::iterator it;
        string ans = "";
        for(it = m.begin(); it != m.end(); it++){
            if(it->second == j && it->first.size() > ans.size()) ans = it->first;
        }
        if(ans.size() < 3) cout << "no significant commonalities" << endl;
        else cout << ans << endl;
    }
    return 0;
}