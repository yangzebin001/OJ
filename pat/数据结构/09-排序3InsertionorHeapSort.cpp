#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 103;

int data1[MAXN];
int data2[MAXN];

void show(int data[],int N){
	for(int i = 0; i < N; i++){
		if(i != 0) cout << " ";
		cout <<data[i];
	}
}

void shiftDown(int arr[],int i,int N){
	//找到三者（父节点与两个子节点）中最大者，如果最大者不是父节点，则需要交换。 
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if(l < N && arr[i] < arr[l]){
		largest = l;
	}else{
		largest = i;
	}
	if(r < N && arr[largest] < arr[r]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i],arr[largest]);
		shiftDown(arr,largest,N);
	}
}

void Heapify(int arr[],int N){
	for(int i = (N-1)/2; i >= 0; i--){
		shiftDown(arr,i,N);
	}
}

bool isSame(int arr1[],int arr2[],int N){
	for(int i = 0; i < N; i++){
		if(arr1[i] != arr2[i])return false;
	}
	return true;
}

int main(){
	int N;
	cin >>N;
	for(int i = 0; i < N; i++){
		cin >> data1[i];
	} 
	for(int i = 0; i < N; i++){
		cin >> data2[i];
	}
	int i = 1;
	while(i < N && data2[i-1] <= data2[i]) i++;
	int j = i;
	while(j < N && data1[j] == data2[j]) j++;
	if(j == N){
		cout << "Insertion Sort" << endl;
		if(i >= N) i = N-1; 
		sort(data2,data2+i+1); 
		show(data2,N);
	}else{
		cout << "Heap Sort" <<endl;
		Heapify(data1,N);
		int len = N;
		while(len > 0 && !isSame(data1,data2,N)){
			swap(data1[len-1],data1[0]);
			shiftDown(data1,0,--len);
		}
		if(len != 0){
			swap(data1[len-1],data1[0]);
			shiftDown(data1,0,--len);
		}
		show(data1,N);
	}
	return 0;
}
