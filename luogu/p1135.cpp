/*
 * @Date: 2020-02-11 18:19:43
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 18:44:26
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n,a,b;
int vis[202],arr[202];
struct node{
    int now,s;
    node(){};
    node(int _now, int _s):now(_now),s(_s){};  
};
int main(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    if(a == b){
        cout << 0;
        return 0;
    }
    queue<node> q;
    q.push(node(a,0));
    node t;
    vis[a] = 1;
    while(q.size()){
        t = q.front(); q.pop();
        int x = t.now, s = t.s;
        if(x == b){
            cout << s;
            return 0;
        }
        if(x-arr[x] >= 1 && !vis[x-arr[x]]){
            q.push(node(x-arr[x],s+1));
            vis[x-arr[x]] = 1;
        }
        if(x+arr[x] <= n && !vis[x+arr[x]]){
            q.push(node(x+arr[x],s+1));
            vis[x+arr[x]] = 1;
        }
    }
    cout << -1;
    return 0;
}
