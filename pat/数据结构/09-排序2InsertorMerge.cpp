#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 105;

int data1[MAXN];
int data2[MAXN];
int temp[MAXN];

int findIndex(int data1[],int data2[],int N){
	int i = N-1;
	while(i >= 0 && data1[i] == data2[i]) i--;
	return i;
}
void show(int data[],int N){
	for(int i = 0; i < N; i++){
		if(i != 0) cout << " ";
		cout << data[i];
	}
	cout << endl;
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> data1[i];
	}
	for(int i = 0; i < N; i++){
		cin >> data2[i];
	}
	int i = 0;
	for(i = 1; i < N; i++){
		if(data2[i+1] < data2[i]) break;
	}
	bool flag = false;
	for(int j = i+1; j < N; j++){
		if(data1[j] != data2[j]){
			flag = true;
			break;
		}
	}
	if(!flag){
		cout << "Insertion Sort" <<endl;
		sort(data1,data1+i+2);
		show(data1,N);
	}else{
		cout << "Merge Sort" << endl;
		for(int i = 1; i <= N; i*=2){ 
			bool flag = true;
			if(findIndex(data1,data2,N) < 0) flag = false;
			for(int j = 0; j < N; j+=i){
				int k = (j+i) > N ? N : j+i;
				sort(data1+j,data1+k);
			}
			if(!flag)break;
		}
		show(data1,N);
	}
	return 0;
} 
