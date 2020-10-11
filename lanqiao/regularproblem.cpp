/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 16:27:19 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 16:32:33
 */
#include<bits/stdc++.h>

using namespace std;
string s;
int ans, len, pos;
int dfs(){
    int nowlen = 0, maxlen = 0;
    while(pos < len){
        if(s[pos] == '('){
            pos++;
            nowlen += dfs();
        }else if(s[pos] == ')'){
            pos++;
            break;
        }else if(s[pos] == '|'){
            maxlen = max(nowlen,maxlen);
            pos++;
            nowlen = 0;
        }else{
            nowlen++;
            pos++;
        }
    }
    maxlen = max(nowlen,maxlen);
    return maxlen;
}
int main(){
    cin >> s;
    len = s.size();
    pos = 0;
    ans = dfs();
    cout << ans;
    return 0;
}