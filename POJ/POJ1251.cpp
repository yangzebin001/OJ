/*
 * @Date: 2019-09-03 10:12:34
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-03 10:28:18
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 30;
const int INF = 0x3f;
struct edge{
    int a,b,w;
    edge(){}
    edge(int _a,int _b,int _w){
        a = _a;
        b = _b;
        w = _w;
    }
    bool operator < (const edge &c)const{
        return w < c.w;
    }
}Edge[MAXN*MAXN];
int M[MAXN][MAXN];
int tol = 0;
void addEdge(int a,int b, int w){
    Edge[tol].a = a;
    Edge[tol].b = b;    
    Edge[tol++].w = w;
}

int F[MAXN];
int Find(int x){
    return F[x] == x ? x : F[x] = Find(F[x]);
}

int Kurskal(int N){
    for(int i = 0; i < N; i++){
        F[i] = i;
    }
    int ans = 0,cnt = 0;
    sort(Edge,Edge+tol);
    for(int i = 0; i < tol; i++){
        int w = Edge[i].w;
        int p = Find(Edge[i].a);
        int q = Find(Edge[i].b);
        if(p != q){
            F[p] = q;
            cnt++;
            ans += w;
            if(cnt == N-1) break;
        }
    }
    return ans;
}


int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n){
        memset(M,INF,sizeof(M));
        tol = 0;
        for(int i = 0; i < n-1; i++){
            char c[2];int a;
            scanf("%s%d",c,&a);
            for(int j = 0; j < a; j++){
                char b[2]; int d;
                scanf("%s%d",b,&d);
                M[c[0]-'A'][b[0]-'A'] = min(M[c[0]-'A'][b[0]-'A'],d);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] != INF) addEdge(i,j,M[i][j]);
            }
        }
        printf("%d\n",Kurskal(n));
    }
    return 0;
}