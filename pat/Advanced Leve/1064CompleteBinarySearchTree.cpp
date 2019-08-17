#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int data[1005];
struct Tree{
	int data;
	Tree* left;
	Tree* right;
	Tree(int data):data(data){
		left = NULL;
		right = NULL;
	}
};
//µ±Ç°²ãÊý 
int getLayer(int nodeNumber){
	if(nodeNumber <= 0) return 0;
	int mi = 1;
	while(pow(2,mi)-1 < nodeNumber){
		mi ++;
	}
	return mi;
}
Tree* getPoint(int* data,int nodeNumber){
	if(nodeNumber < 1) return NULL;
	if(nodeNumber == 1) return new Tree(data[0]);
	int buttomNodeNumber = nodeNumber - 2*(pow(2,getLayer(nodeNumber)-2)-1)-1;
	int leftTreeNode = pow(2,getLayer(nodeNumber)-2);
	int point;
	if(buttomNodeNumber <= leftTreeNode){
		point = nodeNumber - leftTreeNode;
	}else{
		point = pow(2,getLayer(nodeNumber)-1)-1;
	}
	Tree* root = new Tree(data[point]);
	root->left = getPoint(data,point);
	root->right = getPoint(data+point+1,nodeNumber-point-1);
	return root;
} 


int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> data[i];
	}
	sort(data,data+N);
	int nodeNumber = N;
	Tree* root = getPoint(data,nodeNumber);
	queue<Tree*> q;
	q.push(root);
	int flag = 0;
	while(!q.empty()){
		int len = q.size();
		for(int i = 0; i < len; i++){
			Tree* root = q.front();
			q.pop();
			if(flag) cout << " ";
			cout << root->data;
			flag = 1;
			if(root->left) q.push(root->left);
			if(root->right) q.push(root->right);
		}
	}
	return 0;
} 
