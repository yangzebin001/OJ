/*
 * @Date: 2019-08-24 19:57:34
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 08:42:34
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 400;
const int INF = 0x3f3f3f3f;
//地图开大一点，流星范围不代表地图范围
int M[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[] = {0,-1,0,0,1};
int dy[] = {0,0,1,-1,0};
int MAXT;

//标记流星雨到达时间
void dye(int x, int y, int n){
    for(int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN){
            M[nx][ny] = min(M[nx][ny],n);
            vis[nx][ny] = 1;
        }
    }
}
struct node{
    int x,y,s;
    node(){}
    node(int _x,int _y,int _s):x(_x),y(_y),s(_s){}
};



int dfs(){
    //当前时间
    int step = 0;
    //先看源点是否可以走
    if(M[0][0] == 0) return 1;
    queue<node> q;
    q.push(node(0,0,0));
    node temp;
    while(q.size()){
        //只要遍历到最迟流星到达的时间就够了。
        if(step > MAXT) break;
        int len = q.size();
        // printf("%d\n",len);
        for(int i = 0; i < len; i++){
            temp = q.front();q.pop();
            for(int i = 1; i < 5; i++){
                int nx = temp.x + dx[i];
                int ny = temp.y + dy[i];
                int ns = temp.s - 1;
                if(nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN){
                    //到达当前点用-n表示，不管是未知区域还是流星区域，只要在规定时间之前，就可以访问。
                    if(-ns < M[nx][ny]){
                        q.push(node(nx,ny,ns));
                        M[nx][ny] = ns;
                    }
                }
            }
        }
        step++;
    }
    int ans = -INF;
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            //正数找最小 == 负数找最大， 并且流星的地方不能访问。
            if(!vis[i][j] && M[i][j] < 0) ans = max(ans,M[i][j]);
        }
    }
    // printf("\n");
    // 访问不到返回-1
    return ans == -INF ? 1 : ans;
}

int main(){
    freopen("in.txt","r",stdin);
    memset(M,INF,sizeof(M));
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        dye(x,y,c);
        //最迟流星到达时间
        MAXT = max(MAXT,c);
        // printf("%d %d %d\n",x,y,c);
    }
    printf("%d",-dfs());
    return 0;
}
