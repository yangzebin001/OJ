/*
 * @Date: 2020-02-01 19:35:22
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-01 21:45:09
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
const int MAXN = 110;
int a[MAXN][MAXN],dp[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
struct Node{
    int x,y,data;
}node[10010];
bool judge(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}
int cmp(Node a, Node b){
	return a.data > b.data;
}
void solve(){
	int t = 0;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            node[t].x = i, node[t].y = j, node[t++].data = a[i][j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
        }
    }
    sort(node,node+t, cmp);
    for(int i = 0; i < n*n; i++){
    	int x = node[i].x, y = node[i].y, d = node[i].data;
		if(!dp[x][y]) dp[x][y] = d;
		for(int c = 0; c < 4; c++){
			
	    	for(int j = 1; j <= k; j++){
	    		int nx = dx[c]*j + x;
	    		int ny = dy[c]*j + y;
	    		if(judge(nx,ny) && a[nx][ny] < a[x][y]){
	    			dp[nx][ny] = max(dp[nx][ny],dp[x][y]+a[nx][ny]);
				}
			}
		}
	}
	cout << dp[0][0] << endl;
}
int main(){
    while(cin >> n >> k, n != -1 && k != -1){
        solve();
    }
    return 0;
}
