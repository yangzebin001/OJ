/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 14:06:44 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 14:11:24
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 10010;

struct e{
    int u,v,w;
}edge[MAXN*MAXN];
int tol;

bool cmp(e&a, e&b){
    return a.w < b.w;
}
int F[MAXN];

int n,m,k;

int getf(int x){
    return F[x] == x ? x : F[x] = getf(F[x]);
}
int main(){
    cin >> n >> m >> k;
    if(m < n-k){
        cout << "No Answer" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) F[i] = i;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edge[tol].u = u;
        edge[tol].v = v;
        edge[tol++].w = w;
    }
    sort(edge, edge+tol, cmp);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < tol; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int c = getf(u);
        int d = getf(v);
        if(c != d){
            F[c] = d;
            cnt++;
            ans += w;
            if(cnt == n-k) break;
        }
    }
    cout << ans;
    return 0; 
}