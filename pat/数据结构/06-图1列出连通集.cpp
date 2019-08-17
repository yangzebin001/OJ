#include<iostream>
#include<queue>
using namespace std;
int data[12][12];
int data1[12][12];
int node[12];

void dfs(int i,int N){
	for(int j = 0; j < N; j++){
		if(data[j][i] && node[j] == 0){
			cout << j << " ";
			node[j] = 1;
			data[j][i] = 0;
			dfs(j,N);
		}
	}
}
int main(){
	int N,t;
	cin >>N>> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		data[a][b] = 1;
		data[b][a] = 1;
		data1[a][b] = 1;
		data1[b][a] = 1;
	}
	for(int i = 0; i < N; i++){
		data[i][i] = 1;
		if(!node[i]){
			cout << "{ "; 
			dfs(i,N); 
			cout <<"}"<< endl;
		}
	}
	for(int i = 0; i < N; i++){
		node[i] = 0;
		data1[i][i] = 1;
	}
	queue<int> q;
	for(int j = 0; j < N; j++){
		if(!node[j]){
			q.push(j);
			node[j] = 1;
			cout << "{ "; 
			while(!q.empty()){
				int curr_node = q.front();q.pop();
				cout << curr_node << " ";
				for(int i = 0; i < N; i++){
					if(!node[i] && data1[curr_node][i]){
						q.push(i);
						node[i] = 1;
						data1[curr_node][i] = 0;
					}
				}
			}
			cout << "}" << endl; 
		}
		
	}
	
	return 0;
}
