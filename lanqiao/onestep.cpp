#include<bits/stdc++.h>

using namespace std;
set<int> vis;
int main(){
    queue<int> q;
    q.push(0);
    int ans = 0;
    while(1){
        int len = q.size();

        for(int i = 0; i < len; i++){
            int t = q.front(); q.pop();
            if(t == 1){
                cout << ans << endl;
                return 0;
            }
            if(!vis.count(t+97)){q.push(t+97);vis.insert(t+97);}
            if(!vis.count(t-127)){q.push(t-127);vis.insert(t-127);}
        }
        ans++;
    }
    return 0;
}