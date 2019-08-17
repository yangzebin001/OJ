//#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	for(int q = 0; q < a; q++){
		int L, n; 
		scanf("%d%d",&L,&n);
		int x[n];
		for(int i = 0; i < n; i++){
			scanf("%d",&x[i]);
		}
		//最短时间 
		int minT = 0;
		for(int i = 0; i < n; i++){
			//max含义为，最后一只通过后，该蚂蚁群里用的最长的时间。 
			//min含义为，当前蚂蚁通过竿子所用的最短时间。 
			minT = max(minT, min(x[i], L-x[i]));
		} 
		
		//最长时间 
		int maxT = 0;
		for(int i = 0; i < n; i++){
			//第一个max含义为，最后一只通过后，该蚂蚁群里用的最长的时间。 
			//第二个max含义为，当前蚂蚁通过竿子所用的最长时间。 
			maxT = max(maxT, max(x[i], L-x[i]));
		} 
		
		printf("%d %d\n",minT,maxT);
	}
	
	
	return 0; 
}
