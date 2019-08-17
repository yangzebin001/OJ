#include<iostream>
#include<utility>
#include<map>
using namespace std;

int day[1000005];

pair<int,int> ope[1000005];

int main(){
	int n,m;
	int op,s,t;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> day[i];
		pair<int,int> a(0,0);
		ope[i] = a;
	}
	for(int i = 1; i <= m; i++){
		cin >> op >> s >> t;
		if(ope[s].second){
			for(int j = ope[s].first; j < s; j++){
				day[j]+=ope[s].second;
			}
			pair<int,int> a(0,0);
			ope[s] = a;
		}
		for(int j = s; j <= t; j++){
			day[j]-=op;
			if(day[j] < 0){
				cout << -1 <<endl;
				cout << i <<endl;
				return 0;
			}
		}
		pair<int,int> a(s,op);
		ope[t+1] = a;
	}
	cout << 0 << endl;
	return 0;
}
