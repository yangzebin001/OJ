#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
const int MAXN = 1005;

int F[MAXN];
int Rank[MAXN];
bool vis[MAXN];
int dx[MAXN];
int dy[MAXN];



void init(){
	for(int i = 1; i <= MAXN; i++){
		F[i] = i;
		Rank[i] = 1;
	}
}

int _find(int x){
	return F[x] == x ? x : F[x] = _find(F[x]);
}

void _union(int a,int b){
	int x = _find(a);
	int y = _find(b);
	if(x == y) return;
	if(Rank[x] > Rank[y]){
		F[y] = x;
		Rank[x] += Rank[y];
	}else{
		F[x] = y;
		Rank[y] += Rank[x];
	}
}



int main(){
	int N,D;
	scanf("%d%d",&N,&D);
	init();
	int a,b;
	for(int i = 1; i <= N; i++){
		scanf("%d%d",&a,&b);
		dx[i] = a;
		dy[i] = b;
	}
	char op[2];
	while(scanf("%s",op) != EOF){
		if(op[0] == 'O'){
			int a;
			scanf("%d",&a);
			vis[a] = true;
			for(int i = 1; i <= N; i++){
				if(i != a && vis[i]){
					if((dx[i] - dx[a])*(dx[i] - dx[a]) + (dy[i] - dy[a])*(dy[i] - dy[a]) <= D*D){
						_union(a,i);
					}
				}
			}
		}else if(op[0] == 'S'){
			int a,b;
			scanf("%d%d",&a,&b);
			if(_find(a) == _find(b)){
				printf("SUCCESS\n");
			}else{
				printf("FAIL\n");
			}
		}
	}
	
	return 0;
}

