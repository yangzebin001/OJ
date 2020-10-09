/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-08 13:22:20 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-08 13:49:31
 */

#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 600;

struct e{
    int u,v,w;
}edge[MAXN*MAXN];
int tol;

bool cmp(e&a, e&b){
    return a.w < b.w;
}
int F[MAXN];
int M[MAXN][MAXN];
int a,b;

int getf(int x){
    return F[x] == x ? x : F[x] = getf(F[x]);
}

int main(){

    cin >> a >> b;
    for(int i = 0; i < b; i++){
        F[i+1] = i+1;
        for(int j = 0; j < b; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < b; i++) {
        for(int j = i+1; j < b; j++){
            //优惠为0或者优惠原价还大（坑点啊）
            if(M[i][j] == 0 || M[i][j] > a) continue;
            edge[tol].u = i;
            edge[tol].v = j;
            edge[tol++].w = M[i][j];
        }
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
            if(cnt == b-1) break;
        }
    }
    //先要买第一个商品
    ans += a;
    //还有个商品没买
    ans += (b-1-cnt)*a;
    cout << ans;
    return 0;
}