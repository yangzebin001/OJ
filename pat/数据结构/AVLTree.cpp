#include<iostream>
using namespace std;
typedef struct AVLNode* AVLTree;
struct AVLNode{
	int data;
	AVLTree left;
	AVLTree right;
	int height;
	AVLNode(int data):data(data){
		left = NULL;
		right = NULL;
		height = 0;
	}
};

int Max(int a, int b){
	return a > b ? a : b;
}

int GetHeight(AVLTree t){
	if(!t) return 0;
	return t->height;
}

//���� 
AVLTree SingleRightRotation(AVLTree A){
	//�ȼ�¼������,����ڵ����������Ϊ���ڵ�����������ٽ����ڵ���Ϊ��ڵ���������� 
	AVLTree l = A->left;
	A->left = l->right;
	l->right = A;
	//�������ڵ�ĸ߶ȡ� 
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
	l->height = Max(GetHeight(l->left),A->height) + 1;
	return l; 
}

//���� 
AVLTree SingleLeftRotation(AVLTree A){
	//�ȼ�¼������,���ҽڵ����������Ϊ���ڵ�����������ٽ����ڵ���Ϊ�ҽڵ���������� 
	AVLTree r = A->right;
	A->right = r->left;
	r->left = A;
	//�������ڵ�ĸ߶ȡ� 
	A->height = Max(GetHeight(A->left),GetHeight(A->right)) + 1;
	r->height = Max(GetHeight(r->right),A->height) + 1;
	return r;
}

//������ 
AVLTree DoubleRightLeftRotation(AVLTree A){
	//������������ 
	A->right = SingleRightRotation(A->right);
	//�ٽ���ǰ�ڵ����� 
	return SingleLeftRotation(A);
} 

//������ 
AVLTree DoubleLeftRightRotation(AVLTree A){
	//������������ 
	A->left = SingleLeftRotation(A->left);
	//�ٽ���ǰ�ڵ����� 
	return SingleRightRotation(A);
} 

AVLTree Insert(AVLTree T, int X){
	if(!T){
		T = new AVLNode(X);
	}else if(X < T->data){
		T->left = Insert(T->left,X);
		if(GetHeight(T->left)- GetHeight(T->right) == 2){
			if(X < T->left->data){ //���� 
				T = SingleRightRotation(T);
			}else{ //������ 
				T = DoubleLeftRightRotation(T);
			}
		}
	}else if(X > T->data){
		T->right = Insert(T->right,X);
		if(GetHeight(T->right)- GetHeight(T->left) == 2){
			if(X > T->right->data){ //���� 
				T = SingleLeftRotation(T);
			}else{ //������ 
				T = DoubleRightLeftRotation(T);
			}
		}
	}
	//���¸߶� 
	T->height = Max(GetHeight(T->left),GetHeight(T->right))+1;
	return T;
} 

int main(){
	int N,root;
	cin >> N;
	AVLTree r = NULL;
	if(N){

		for(int i = 0; i < N; i++){
			cin >> root; 
			r = Insert(r,root);
		} 
		cout << r->data << endl;
	}
	
	return 0;
} 
