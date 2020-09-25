/*
 * @Date: 2020-05-09 14:04:42
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 14:04:43
 */
/*
 * @Date: 2020-05-09 13:28:53
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-05-09 13:34:35
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int INF = 0x3f3f3f3f;
int M[40][40];
int dp[40][40];
int vis[40][40]; 
	int len = 20,len2 = 20;
void update(){
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	vis[1][1] = 1;
	while(q.size()){
		pair<int,int> c = q.front();
		q.pop();
		int x = c.first, y = c.second;
		
		int t = M[x][y];
		for(int i = 1; i * i <= t; i++){
			if(t%i == 0){
				int j = t/i;
				if(i <= len && j <= len2){
					cout << i << " " << j << endl;
					dp[i][j] = min(dp[x][y]+1,dp[i][j]);
					dp[j][i] = min(dp[x][y]+1,dp[j][i]);
					if(!vis[i][j]){
						q.push(make_pair(i,j));
						vis[i][j] = 1;
					}
					if(!vis[j][i]){
						q.push(make_pair(j,i));
						vis[j][i] = 1;
					}
				}
			}
		}
	}
}
int main(){
	memset(dp,INF,sizeof(dp));

	for(int i = 1; i <= len; i++){
		for(int j = 1; j <= len2; j++){
			scanf("%d",&M[i][j]);
		}
	}
	dp[1][1] = 0;
//  	for(int i = 1; i <= len; i++){
//		for(int j = 1; j <= len; j++){
			update();
//		}
//	}
  	printf("%d",dp[len][len2]);
    return 0;
}