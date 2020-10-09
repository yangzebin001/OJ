/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 09:30:58 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 09:38:26
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 2e4+10;

int F[MAXN];

int getf(int x){
    return F[x] == x ? x : F[x] = getf(F[x]);
}

int merge(int x, int y){
    F[getf(x)] = getf(y);
}

struct e{
    int u,v,w;
}edge[MAXN];

bool cmp(e &a, e &b){
    return a.w < b.w;
}
int tol = 0;

int n,m,s,t;
int main(){
    
    cin >> n >> m >> s >> t;
    for(int i = 0; i <= n; i++) F[i] = i;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge[tol].u = u;
        edge[tol].v = v;
        edge[tol++].w = w;
    }
    sort(edge, edge+tol, cmp);
    for(int i = 0; i < tol; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int a = getf(u);
        int b = getf(v);
        if(a != b){
            F[a] = b;
            if(getf(s) == getf(t)){
                cout << w << endl;
                return 0;
            }
            
        }
    }
    return 0;
}