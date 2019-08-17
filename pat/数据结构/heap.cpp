#include<iostream>
#include<algorithm> 
using namespace std;


//下滤操作。 
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

void shiftUp(int arr[],int &N,int el){
	arr[N] = el;
	int child = N++;
	for(; child && arr[(child-1)/2] < arr[child]; child = (child-1)/2){
		swap(arr[child],arr[(child-1)/2]);
	}
}

int extractMax(int arr[],int &N){
	if(N < 0){
		printf("heap underflow!");;
		return -1;
	}
	int maxElement = arr[0];
	arr[0] = arr[--N];
	shiftDown(arr,0,N);
	return maxElement;
}

void Heapify(int arr[],int N){
	for(int i = (N-1)/2; i >= 0; i--){
		shiftDown(arr,i,N);
	}
}

void heapsort(int arr[],int N){
	int len = N;
	Heapify(arr,len);
	for(int i = len; i > 0; i--){
		swap(arr[len-1],arr[0]);
		shiftDown(arr,0,--len);
	}
}

int main(){
	int arr[] = {16,4,10,14,7,9,3,2,8,1,5};
	int len = 11;
	Heapify(arr,len);
	int me = extractMax(arr,len);
	cout << "the maximum element is:" << me << endl;
//	heapsort(arr,len);
	for(int i = 0; i < len; i ++){
		cout << arr[i] << " ";
	}
	cout << endl;
	shiftUp(arr,len,11);
	for(int i = 0; i < len; i ++){
		cout << arr[i] << " ";
	}
	return 0;
} 
