#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 200005;

int F[MAXN];
int Rank[MAXN];
void init(int N){
	for(int i = 0; i <= 2*N; i++){
		F[i] = i;
		Rank[i] = 1;
	}
}
int _find(int x){
	return F[x] == x ? x : F[x] = _find(F[x]);
}
void _union(int a, int b){
	a = _find(a);
	b = _find(b);
	if(a == b) return;
	if(Rank[a] > Rank[b]){
		F[b] = a;
		Rank[a] += Rank[b];
	}else{
		F[a] = b;
		Rank[b] += Rank[a]; 
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M;
		scanf("%d%d",&N,&M);
		init(N);
		for(int i = 1; i <= M; i++){
			char op[2];
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if(op[0] == 'A'){
				 if(_find(a) == _find(b)){
					printf("In the same gang.\n");
				}else if(_find(a) == _find(b+N)){
					printf("In different gangs.\n");
				}else{
					printf("Not sure yet.\n");
				}
			}else{
				_union(a,b+N);
				_union(a+N,b);
			}
		}
	}
	
	
	
	return 0;
}
