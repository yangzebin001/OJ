/*
 * @Date: 2020-02-15 15:18:46
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-15 15:18:47
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,ans,arr[2520][2520],dp[2520][2520];
int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if(arr[i][j]) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i][j]){
				int m1=0,m2=0,m3=0;
				for(int y = j-1; y >= 1 && !arr[i][y]; y--,m1++);
				for(int x = i-1; x >= 1 && !arr[x][j]; x--,m2++);
				for(int y = j+1; y <= m && !arr[i][y]; y++,m3++);
				dp[i][j] = max(dp[i][j],min(dp[i-1][j-1],min(m1,m2))+1);
				dp[i][j] = max(dp[i][j],min(dp[i-1][j+1],min(m2,m3))+1);
			}
			ans = max(ans,dp[i][j]);
		}
	}
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans;
	return 0;
}