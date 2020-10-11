/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 15:48:31 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-11 15:48:31 
 */
#include<bits/stdc++.h>

using namespace std;

string s = "012345678";
set<string> vis;
int main(){
    int ans = 0;
    queue<string> q;
    q.push(s);
    while(q.size()){
        int len = q.size();
        for(int i = 0; i < len; i++){

            string t = q.front();
            if(t == "087654321"){
                cout << ans << endl;
                return 0;
            }
            q.pop();
            if(vis.count(t)) continue;
            vis.insert(t);
            int zeropos = t.find('0');
            swap(t[zeropos], t[(zeropos+1)%9]);
            q.push(t);
            swap(t[zeropos], t[(zeropos+1)%9]);
            swap(t[zeropos], t[(zeropos-1+9)%9]);
            q.push(t);
            swap(t[zeropos], t[(zeropos-1+9)%9]);
            swap(t[zeropos], t[(zeropos-2+9)%9]);
            q.push(t);
            swap(t[zeropos], t[(zeropos-2+9)%9]);
            swap(t[zeropos], t[(zeropos+2+9)%9]);
            q.push(t);
        }
        ans++;
    }
    return 0;
}