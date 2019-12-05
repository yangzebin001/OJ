/*
 * @Date: 2019-10-25 22:21:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-25 23:04:58
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

const int MAXN = 1e3+10;
typedef pair<int,int> P;
P edge[MAXN*MAXN+10];
int father[MAXN*MAXN+10];
int n,m,k;
int F(int x){
    return father[x] == x ? x : father[x] = F(father[x]);
}
void M(int a, int b){
    int x = F(a);
    int y = F(b);
    if(x != y) father[x] = y;
}

int solve(int x){
    for(int i = 1; i <= n; i++) father[i] = i;
    for(int i = 0; i < m; ++i){
        if(edge[i].first == x || edge[i].second == x) continue;
        M(edge[i].first,edge[i].second);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(father[i] == i) cnt++;
    return cnt-2;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[i].first = a;
        edge[i].second = b;
    }
    for(int i = 0; i < k; i++){
        int p;
        scanf("%d",&p);
        
        printf("%d\n",solve(p));
    }
    return 0;
}