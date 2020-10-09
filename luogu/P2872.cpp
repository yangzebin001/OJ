#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<climits>
using namespace std;
int n,m;
const int MAXN = 1000100;
struct e{
    int u, v;
    double dis;
}edge[MAXN];

bool cmp(struct e& a, struct e& b){
    return a.dis < b.dis;
}

double x[MAXN];
double y[MAXN];
int a[MAXN],b[MAXN];

int xi,yi;
int F[MAXN];
int getf(int x){
    return F[x] == x ? x : F[x] = getf(F[x]);
}

double getdis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < MAXN; i++) F[i] = i;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < m; i++){
        int c,d;
        cin >> c >> d;
        F[getf(c)] = getf(d);
    }
    int tol = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            // cout << i << " " << j << endl;
            edge[tol].u = i;
            edge[tol].v = j;
            edge[tol++].dis = getdis(x[i], y[i], x[j], y[j]);
        }
    }
    sort(edge, edge+tol, cmp);
    double ans = 0;
    int cnt = 0;
    for(int i = 0; i < tol; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        double dis = edge[i].dis;
        // cout << dis << endl;
        int a = getf(u);
        int b = getf(v);
        if(a != b){
            F[a] = b;
            ans += dis;
            cnt++;
            if(cnt == n-1-m) break;
        }
    }
    printf("%.02f", ans);
    return 0;
}