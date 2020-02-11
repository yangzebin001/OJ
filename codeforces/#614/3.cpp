/*
 * @Date: 2020-01-19 22:39:48
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-19 23:17:15
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
const int MAXN = 1e5+10;
bool M[MAXN][2];
bool vis[MAXN][2];
int n;
void solve(int a,int b){
    M[a][b] = !M[a][b];
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    memset(vis,0,sizeof(vis));
    vis[1][1] = 1;
    while(q.size()){
        pair<int,int> now = q.front(); q.pop();
        int x = now.first, y = now.second;
        // cout << x <<" " << y << endl;
        if(x == 2 && y == n){
            printf("Yes\n");
            return;
        }
        if(x == 1){
            if(!M[x+1][y] && !vis[x+1][y]){
                q.push(make_pair(x+1,y));
                vis[x+1][y] = 1;
            }
        }else if(x == 2){
            if(!M[x-1][y] && !vis[x-1][y]){
                q.push(make_pair(x-1,y));
                vis[x-1][y] = 1;
            }
        }
        if(y+1 <= n &&!M[x][y+1]){
            q.push(make_pair(x,y+1));
        }
    }
    printf("No\n");
    return;
}
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int q;
    scanf("%d%d",&n,&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        solve(a,b);
    }
}