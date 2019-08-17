#include<iostream>
#include<cstdio>
#define maxn 30005

using namespace std;

int father[maxn],rank[maxn];

void Init(int N){
	for(int i = 0; i < N; i++){
		father[i] = i;
		rank[i] = 1;
	}
}

int find_set(int node){
	return father[node] == node ? node: father[node] = find_set(father[node]);
}

int _union(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if(x == y) return 0;
	if(rank[x] < rank[y]){
		father[x] = y;
		rank[y] += rank[x];
	} else{
		father[y] = x;
		rank[x] += rank[y];
	}
	return 1;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){
		if(n == 0 && m == 0) return 0; 
		Init(n);
		for(int i = 0; i < m; i++){
			int cot,first;
			scanf("%d%d",&cot, &first);
			for(int j = 1; j < cot; j++){
				int t;
				scanf("%d", &t);
				_union(first,t);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(find_set(i) == find_set(0)) ans++;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
