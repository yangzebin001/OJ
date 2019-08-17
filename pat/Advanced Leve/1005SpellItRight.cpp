#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string digits[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string a;
	cin >> a;
	int sum = 0;
	for(int i = 0; i < a.size(); i++){
		sum += (a[i]-'0');
	}
	int flag  = 0;
	vector<int> v;
	while(sum){
		int i = sum %10;
		sum /= 10;
		v.push_back(i);
	}
	if(v.size() == 0) cout << "zero";
	for(int i = v.size()-1; i>=0; i--){
		if(i != v.size()-1) cout << " ";
		cout << digits[v[i]];
	}
	return 0;
} 
