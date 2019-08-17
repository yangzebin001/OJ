#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
#define maxn 3000
#define P pair<int, int> 
using namespace std;

P cow[maxn],bot[maxn];
int main(){
	priority_queue<int, vector<int>, greater<int> > pq;
	int ans = 0;
	int C,L;
	cin >> C >> L;
	for(int i = 0; i < C; i++){
		scanf("%d%d",&cow[i].first,&cow[i].second);
	}
	for(int i = 0; i < L; i++){
		scanf("%d%d",&bot[i].first,&bot[i].second);
	}
	
	sort(cow,cow+C);
	sort(bot,bot+L);
	int j = 0;
	for(int i = 0; i < L; i++){
		while(cow[j].first <= bot[i].first && j < C){
			pq.push(cow[j].second);
			j++;
		}
		while(!pq.empty() && bot[i].second){
			int x = pq.top();
			pq.pop();
			if(x < bot[i].first) continue;
			bot[i].second--;
			ans++;
		}
	}
	cout << ans;
	return 0;
	 
} 
