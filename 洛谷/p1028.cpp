#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int f[1005];



int main(){
	int n;
	cin >> n;
	for(int i = 1; i <=n; i++){
	
		for(int j = 1; j <= i/2; j++){
			
			f[i] += f[j];
		}
		f[i]++;
	}		
	cout << f[n];
	return 0;
} 
