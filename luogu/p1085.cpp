#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int a,b,sum = 0,day = 0;
	for(int i = 0; i < 7; i++){
		cin >> a >> b;
		if(sum < a+b){
			sum = a+b;
			day = i+1;
		}
	}
	cout << day;
	return 0;
} 