#include<iostream>
#include<set>
#include<algorithm>
#define MAXN 10005 

using namespace std;
int father[MAXN];

void Init(int N){
	for(int i = 1; i <= N; i++){
		father[i] = -1;
	}
}

int find_set(int node){
	return father[node] < 0 ? node : father[node] = find_set(father[node]);
}

void _union(int x, int y){
	int a = find_set(x);
	int b = find_set(y);
	if(a != b){
		if(father[a] > father[b]){
			father[b] += father[a];
			father[a] = b;
		}else{
			father[a] += father[b];
			father[b] = a;
		}
	}
}

bool issame(int x, int y){
	return find_set(x) == find_set(y);
}
int main(){
	int N;
	cin >> N; 
	Init(N);
	char op;
	int a,b;
	cin >> op;
	while(op != 'S'){
		cin >> a >> b;
		if(op == 'I'){
			_union(a,b);
		}else{
			if(issame(a,b)){
				cout << "yes" << endl;
			}else{
				cout << "no" << endl;
			}
		}
		cin >> op;
	}
//	set<int> s;
//	for(int i = 1; i <= N; i++){
//		s.insert(father[i]);
//	}
//	if(s.size()!=1)
//		cout << "There are "<<s.size()<<" components." << endl;
//	else 
//		cout << "The network is connected." <<endl;
	int cont = 0;
	
	for(int i = 1; i <= N; i++){
		if(father[i] < 0){
			cont++;
		}
	}
	if(cont!=1)
		cout << "There are "<<cont<<" components." << endl;
	else 
		cout << "The network is connected." <<endl;
	return 0;
}
