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
		//���ʱ�� 
		int minT = 0;
		for(int i = 0; i < n; i++){
			//max����Ϊ�����һֻͨ���󣬸�����Ⱥ���õ����ʱ�䡣 
			//min����Ϊ����ǰ����ͨ���������õ����ʱ�䡣 
			minT = max(minT, min(x[i], L-x[i]));
		} 
		
		//�ʱ�� 
		int maxT = 0;
		for(int i = 0; i < n; i++){
			//��һ��max����Ϊ�����һֻͨ���󣬸�����Ⱥ���õ����ʱ�䡣 
			//�ڶ���max����Ϊ����ǰ����ͨ���������õ��ʱ�䡣 
			maxT = max(maxT, max(x[i], L-x[i]));
		} 
		
		printf("%d %d\n",minT,maxT);
	}
	
	
	return 0; 
}
