#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 20010, M = 200010;

int color[N];
int n,m;

struct edge{
    int u, v;
    edge(){}
    edge(int _u, int _v){
        u = _u;
        v = _v;
    }
};
vector<edge> ed[N];

//判断由所有点以及所有权值大于 limit 的边构成的新图是否是二分图。
bool dfs(int u, int c, int limit){
    color[u] = c;
    for(int i = 0; i < ed[u].size(); i++){
        int v = ed[u][i].u, w = ed[u][i].v;
        if(w <= limit) continue; //只看组间的边（大于limit的边），组内的边不用看
        if(color[v]){
            if(color[v] == c) return false;
        }
        else if(!dfs(v, 3-c, limit)) return false;
    }
    return true;
}

bool check(int limit){
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(!dfs(i, 1, limit)) return false;
        }
    }
    return true;
}

int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ed[a].push_back(edge(b,c));
        ed[b].push_back(edge(a,c));

    }
    int l = 0, r = 1e9+10;
    while(l < r){
        int mid = l+r>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d",l);
    return 0;
}