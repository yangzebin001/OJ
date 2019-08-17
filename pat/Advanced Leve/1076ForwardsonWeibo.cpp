#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int users[1005];
int map[1005][1005];

void clearU(int N){
	for(int i = 1; i <= N; i++){
		users[i] = 0;
	}
}



int main(){
	int N,L;
	cin >> N >> L;
	for(int i = 1; i <=N; i++){
		int t;
		cin >> t;
		for(int j = 0; j < t; j++){
			int a;
			cin >> a; 
			map[a][i] = 1;
		}
	}
	int t;
	cin >> t;
	while(t--){
		queue<int> q;
		clearU(N); 
		int a;
		cin >> a;
		q.push(a);
		users[a] = 1;
		int layer = 0;
		while(!q.empty()){
			int len = q.size();
			layer++;
			if(layer > L) break;
			for(int j = 0; j < len; j++) {
				int curr = q.front(); q.pop();
				for(int i = 1; i <= N;i++){
					if(map[curr][i] && !users[i]){
						users[i] = 1;
						q.push(i);
					}
				}
			}
		}
		int cont = 0;
		for(int i = 1; i <= N; i++){
			if(users[i])cont++;
		}
		cout << cont-1 << endl; 
	}
	return 0;
} 
