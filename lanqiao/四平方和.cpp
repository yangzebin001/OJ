#include<iostream>
#include<cmath>
#include<map> 
using namespace std;
map<int,int> m;
int N;
int main(){
	scanf("%d", &N);
	for(int c = 0; c * c <= N; c++){
		for(int d = c; c*c + d*d <= N; d++){
			if(m.find(c*c+d*d) == m.end()) m[c*c+d*d] = c; 
		}
	}
	
	for(int a = 0; a*a <= N/4; a++){
		for(int b = a; a*a + b*b <= N/2; b++){
			int rest = N- a*a - b*b;
			if(m.find(rest) != m.end()) {
				printf("%d %d %d %d\n", a,b,m[rest],(int)sqrt(N-a*a - b*b - m[rest]*m[rest]));
				return 0;
			}
		}
	}
	
	
	return 0;
} 
