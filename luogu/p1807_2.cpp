#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
#include<cstdio>
using namespace std;

const int MAXN = 50100;

int m[MAXN][2], dis[MAXN], w[MAXN];
int a,b;
int main(){
    cin >> a >> b;
    //距离无限大
    for(int i = 0; i <= b; i++) dis[i] = w[i] = INT_MAX;
    for(int i = 1;  i <= b; i++){
        int u,v,ww;
        cin >> u >> v >> ww;
        //边的两个点 以及权值，因为求最长路，所以权值取反
        m[i][0] = u, m[i][1] = v, w[i] = -ww;
    }
    dis[1] = 0;
    // 因为从源点到图中任意一点的的所经过的结点数不会超过n个（包括源点与终点），所以执行n-1（最多的边数）轮操作。n为顶点数
    for(int i = 1; i < a; i++){
        //对m条边进行松弛操作。
        for(int j = 1; j <= b; j++){
            dis[m[j][1]] = min(dis[m[j][1]], dis[m[j][0]] + w[j]);
        }
    }
    //因为dis[1] = 0 经过松弛操作后，最大的代价就为0
    if(dis[a] == 0) printf("-1\n");
    else printf("%d\n", -dis[a]);
    // for(int i = 1; i <= b; i++){
    //     printf("%d ", w[i]);
    // }
    return 0;
}