#include<iostream>
#include<cmath>
using namespace std;

int amap[120][120];
int step;
int islandwidth = 7;

bool canjump(int ax,int ay, int bx, int by){
	if(abs(ax-bx) <= step && abs(ay-by) <= step) return true;
	return false; 
} 



bool firstjump(int x,int y){
	for(int i = 50 - islandwidth; i <= 50 + islandwidth; i++){
		for(int j = 50 - islandwidth; j <= 50 + islandwidth; j++)
			if(canjump(x,y,i,j)) return true;
	}
	return false;

} 
//该点是否可以到达岸边
bool isSave(int x,int y){
	if(x-step <= 0 || x + step >= 100 || y-step <= 0 || y-step >= 100) return true;
	return false;
} 
int dfs(int x, int y){
	amap[x][y] = 2;
	if(isSave(x,y)) return 1;
	int ans = 0;
	for(int i = x - step; i <= x + step; i++){
		for(int j = y - step; j <= y + step; j++){
			if(amap[i][j] == 1 && canjump(x,y,i,j)){
				ans = dfs(i,j);
				if(ans) break;
			}
		}
	}
	return ans;
}


int main(){
	int a,b;
	int t;
	cin >> t >> step;
	int O[2] = {50,50};
	while(t--){
		cin >> a >> b;
		amap[50-a][50-b] = 1;
	}
	amap[50][50] = 2;
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(amap[i][j] == 1 && firstjump(i,j)){
				if(dfs(i,j)){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
