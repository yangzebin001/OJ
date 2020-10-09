/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 09:09:36 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 09:25:49
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 2e4+10;
const int INF = 0x3f3f3f3f;
int n,m,s,t;


struct e{
    int v,cost;
    e(){}
    e(int _v, int _cost){
        v = _v;
        cost = _cost;
    }
    bool operator<(const e &b)const{
        return cost > b.cost;
    }
};

vector<e> edge[MAXN];

int vis[MAXN], dis[MAXN];


bool check(int x){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    priority_queue<e> q;
    q.push(e(s,dis[s]));
    while(q.size()){
        int u = q.top().v, w = q.top().cost;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i].v;
            int c = edge[u][i].cost;
            if(c > x) continue;
            if(!vis[v] && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push(e(v,dis[v]));
            }
        }
    }
    return dis[t] < INF;
}

int main(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge[u].push_back(e(v,w));
        edge[v].push_back(e(u,w));
    }

    int l = 0, r = INF;
    while(l < r){
        int mid = l+r>>1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << l << endl;
    
    return 0;
}