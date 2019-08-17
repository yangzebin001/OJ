#include<iostream>
using namespace std;


void insert(int H[],int X,int& size){
	int i;
	for(i = ++size; H[i/2] > X; i /= 2){
		H[i] = H[i/2];
	}
	H[i] = X;
} 
void save(int H[],int index){
	while(1){
		printf("%d",H[index]);
		if(index == 1) return;
		printf(" ");
		index/=2;
	}
}
 
int main(){
	int N,M;
	cin >> N >> M;
	int H[N];
	int size = 1;
	int data;
	H[0] = -10001;
	for(int i = 0; i < N; i++){
		cin >> data;
		insert(H,data,size);
	} 
	for(int i = 0; i < M; i++){
		cin >> data;
		save(H,data);
		printf("\n");
	}
	return 0; 
} 
