#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int M,N,K;
	cin>>M >> N >>K;
	for(int i = 0; i < K; i++){
		stack<int> s;
		vector<int> v;
		int index = 1;
		int vi = 0;
		int flag = 0;
		for(int j = 0; j < N; j++){
			int t;
			cin >> t;
			v.push_back(t);
		}
		while(index <= N){
			if(s.empty()){
				s.push(index++);
			}
			if(s.top() == v[vi]){
				s.pop();
				vi++;
			}else{
				s.push(index++);
				if(s.size() > M){
					flag = 1;
					break;
				}
			}
		}
		if(flag){
			cout << "NO" << endl;
		}else if(!s.empty()){
			while(!s.empty() && vi < v.size()){
				if(s.top() != v[vi++]) break;
				s.pop();
			}
			if(!s.empty())
				cout << "NO" << endl;
			else cout << "YES"<<endl;
		}else{
			cout << "YES"<<endl;
		}
		
	} 
	return 0;
} 
