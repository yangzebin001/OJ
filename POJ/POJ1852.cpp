#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int M;
	cin >> M;
	while(M--){
		int len,N;
		cin >>len >> N;
		int minlen = 0,maxlen = 0;
		for(int i = 0; i < N; i++){
			int a;
			cin >> a;
			minlen = max(minlen,min(a,len-a));
			maxlen = max(maxlen,max(a,len-a));
		}
		cout << minlen <<" "<< maxlen << endl;
	}
	
	return 0;
}
