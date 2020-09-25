#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct node{
    int v, w;
    node(){}
    node(int _v, int _w){
        v = _v;
        w = _w;
    }
};
int n,m;
const int MAXN = 2000;
int dis[MAXN], ind[MAXN];
vector<node> edge[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ind[v]++;
        edge[u].push_back(node(v,w));
    }
    for(int i = 1; i <= n; i++) dis[i] = INT_MIN;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0) q.push(i);
    }
    // q.push(1);
    dis[1] = 0;
    while(q.size()){
        int now = q.front(); q.pop();
        for(int i = 0; i < edge[now].size(); i++){
            int v = edge[now][i].v, w = edge[now][i].w;
            dis[v] = max(dis[v], dis[now]+w);
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    } 
    if(dis[n] == INT_MIN){
        cout << -1 << endl;
    }else{
        cout << dis[n] << endl;
    }
    return 0;
}