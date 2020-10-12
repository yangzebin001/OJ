/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 21:13:34 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-12 21:13:34 
 */
#include<bits/stdc++.h>

using namespace std;
int k,ans;
string s;
vector<int> apos, bpos;
bool check(char c){
    return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main(){
    cin >> k;
    getchar();
    getline(cin,s);
    s = " " + s + " ";
    for(int i = 0; i < s.size()-5; i++){
        if(s.substr(i,5) == "Alice" && check(s[i-1]) && check(s[i+5]) ){
            apos.push_back(i);
        }
    }
    for(int i = 0; i < s.size()-3; i++){
        if(s.substr(i,3) == "Bob" && check(s[i-1]) && check(s[i+3])){
            bpos.push_back(i);
        }
    }
    int j = 0;
    for(int i = 0; i < apos.size(); i++){
        while(j < bpos.size() && bpos[j] < apos[i]) j++;
        int t = j;
        while(t < bpos.size() && apos[i] + 5 + k >= bpos[t]) t++, ans++;
    }
    j = 0;
    for(int i = 0; i < bpos.size(); i++){
        while(j < apos.size() && apos[j] < bpos[i]) j++;
        int t = j;
        while(t < apos.size() && bpos[i] + 3 + k >= apos[t]) t++, ans++;
    }
    cout << ans;
    return 0;
}