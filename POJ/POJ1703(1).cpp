#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100005;

int Rank[MAXN];
int F[MAXN];

int _find(int x){
	if(F[x] == x) return x;
	int rootx = _find(F[x]);
	Rank[x] = (Rank[x] + Rank[F[x]])%2;
	F[x] = rootx;
	return F[x];
}

void _union(int a, int b){
	int x = _find(a);
	int y = _find(b);
	if(x != y){
		Rank[y] = (Rank[x] + Rank[y] + 1) %2;
		F[y] = x;
		
	}
}
void init(int N){
	for(int i = 1; i <= N; i++){
		F[i] = i;
		Rank[i] = 0;
	}
} 
int main(){
	init(200);
	_union(1,2);
	_union(2,3);
	_union(2,4);
	cout << _find(2);
	return 0;
} 
