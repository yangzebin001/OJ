#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int V[11];
vector<vector<int> > E;
void dfs(int i){
	if(!V[i]){
		cout << i << " ";
		V[i] = 1;
		for(int j = 0; j < E[i].size(); j++){
			dfs(E[i][j]);
		}
		
	}

	
}

int main(){
	
	int N,t;
	cin >> N >> t;
	for(int i = 0; i < N; i++){
		E.push_back({}); 
	}
	while(t--){
		int a,b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);			
	}
	for(int i = 0; i < N; i++){
		sort(E[i].begin(),E[i].end());
	}
	for(int i = 0; i < N; i++){
		if(!V[i]){
			cout << "{ ";
			dfs(i);
			cout << "}" << endl;
		}
	}
	
	for(int i = 0; i < N; i++){
		V[i] = 0;
	} 
	queue<int> q;
	for(int i = 0; i < N; i++){
		if(!V[i]){
			q.push(i);
			V[i] = 1;
			cout << "{ ";
		
			while(!q.empty()){
				int a = q.front();q.pop();
				cout << a << " ";
				for(int j =0; j < E[a].size(); j++){
					if(!V[E[a][j]]){
						q.push(E[a][j]);
						V[E[a][j]] = 1;
					}
				} 
			}
			cout << "}"<<endl;
		}
	} 
	return 0;
}
