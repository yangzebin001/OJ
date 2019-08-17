#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int > > E;

int V[10009];

void clearV(int N){
	for(int i = 1; i <= N; i++){
		V[i] = 0;
	}
}
void addEdge(int w,int v){
	E[w].push_back(v);
	E[v].push_back(w);
}

int main(){
	int N,t;
	cin >> N >>t;
	
	for(int i = 0; i <= N; i++){
		E.push_back(vector<int>());
	}
	while(t--){
		int a,b;
		cin >> a >> b;
		addEdge(a,b);
	}
	for(int i = 1; i <= N; i++){
		queue<int> q;
		clearV(N);
		q.push(i);
		V[i] = 1;
		int cont = 0;
		int degree = 0;
		while(!q.empty()){
			int len = q.size();
			if(degree > 6)break;
			degree++;
			for(int k = 0; k < len; k++){
				int curr_i = q.front(); q.pop();
				cont++;
				for(int j = 0; j < E[curr_i].size(); j++){
					if(!V[E[curr_i][j]]){
						V[E[curr_i][j]] = 1;
						q.push(E[curr_i][j]);
					}
				}
			} 
		}
		printf("%d: %.2lf%%\n",i,cont*1.0/N*100);
		
	}
	return 0;
}
