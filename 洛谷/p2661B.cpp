#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 300000;
const int INF = 0x3f3f3f3f;

int F[MAXN];
int cnt;
int ans = INF;

int N;
int fa(int x,int &cnt){
	cnt++;
	return F[x] == x ? x : fa(F[x],cnt);
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		F[i] = i;
	}
	for(int i = 1; i <= N; i++){
		int j;
		scanf("%d",&j);
		cnt = 0;
		//当前可以走到终点吗？如果能走到，说明再连接会形成环。
		if(fa(j,cnt) == i){
			ans = min(ans,cnt);
		}
		else{
			// 更新终点
			F[i] = j;
		}
	}
	printf("%d",ans);
	return 0;
}
