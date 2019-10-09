/*
 * @Date: 2019-10-07 18:55:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-08 22:59:49
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10000+10;
const int INF = 0x3f3f3f3f;
int n,p,k;
struct node{
    int b,ca;
    node(int _b,int _ca):b(_b),ca(_ca){}
    node(){}
    bool operator<(const node &q)const{
        return ca > q.ca;
    }
};
vector<node> V[MAXN];
int dis[MAXN]; //dis存超过目标值x的电话线条数。
int vis[MAXN];
int cost[MAXN];
int Dijkstra(int x){
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1] = 0;
    priority_queue<node> q;
    q.push(node(1,dis[1]));
    node temp;
    while(!q.empty()){
        temp = q.top(); q.pop();
        int u = temp.b;
        if(vis[u])continue;
        vis[u] = 1;
        for(int i = 0; i < V[u].size(); i++){
            int v = V[u][i].b;
            int c = V[u][i].ca;
            c = c > x ? 1 : 0;
            //更新到当前结点的超过x的条数
            if(!vis[v] && dis[v] > dis[u] + c){
                
                dis[v] = dis[u] + c;
                q.push(node(v,dis[v]));
            }
        }
    }
    //是
    return dis[n]<= k;
}




int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&p,&k);
    for(int i = 0; i < p; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        V[a].push_back(node(b,c));
        V[b].push_back(node(a,c));
        cost[i+1] = c; 
    }
    //按长度进行二分，根据超过该长度的个数是否超过k来确定边界。
    sort(cost+1,cost+1+p);
    if(!Dijkstra(cost[p])){
        printf("-1\n");
        return 0;
    }
    //答案有可能是0，所以从0开始。
    int l = 0, r = p-1;
    while(l < r){
        int mid = l+r>>1;
        if(Dijkstra(cost[mid])) r = mid;
        else l = mid+1;
    }
    printf("%d",cost[l]);
    return 0;
}