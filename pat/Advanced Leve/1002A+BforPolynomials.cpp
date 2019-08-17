#include<iostream>
#include<cstdio>
using namespace std;
double polynomials[1005];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int N;
		double K;
		cin >> N >> K;
		polynomials[N] += K;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		int N;
		double K;
		cin >> N >> K;
		polynomials[N] += K;
	}
	int count = 0;
	for(int i = 0; i <= 1000; i++){
		if(polynomials[i] != 0.0){
			count++;
		}
	}
	printf("%d",count);
	for(int i = 1000; i >= 0; i--){
		if(polynomials[i] != 0)
			printf(" %d %.1lf",i,polynomials[i]);
	}
	return 0;
}
