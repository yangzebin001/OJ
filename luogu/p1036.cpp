#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
int m,n;
int arr[25]; 
int ans = 0;
bool isPrime(int a){
	if(a <= 1) return false;
	for(int i = 2; i*i <= a; i++){
		if(a%i == 0) return false;
	}
	return true;
}

void dfs(int i,int sum,vector<int> &v){
	if(sum + n-i < m) return;
	if(sum == m) {
		int s = 0;
		for(int i = 0; i < v.size(); i++) s += v[i];
		if(isPrime(s)) ans++;
		return;
	}
	dfs(i+1,sum,v);
	v.push_back(arr[i]);
	dfs(i+1,sum+1,v);
	v.pop_back();
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	vector<int> v;
	dfs(0,0,v);
	// for(int i = 1; i < 50; i++){
	// 	if(isPrime(i)) cout << i << endl;
	// }
	printf("%d",ans);
	return 0;
} 
