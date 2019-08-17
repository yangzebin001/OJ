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

//右旋 
AVLTree SingleRightRotation(AVLTree A){
	//先记录左子树,将左节点的右子树变为根节点的左子树，再将根节点作为左节点的右子树。 
	AVLTree l = A->left;
	A->left = l->right;
	l->right = A;
	//更新两节点的高度。 
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
	l->height = Max(GetHeight(l->left),A->height) + 1;
	return l; 
}

//左旋 
AVLTree SingleLeftRotation(AVLTree A){
	//先记录右子树,将右节点的左子树变为根节点的右子树，再将根节点作为右节点的左子树。 
	AVLTree r = A->right;
	A->right = r->left;
	r->left = A;
	//更新两节点的高度。 
	A->height = Max(GetHeight(A->left),GetHeight(A->right)) + 1;
	r->height = Max(GetHeight(r->right),A->height) + 1;
	return r;
}

//右左旋 
AVLTree DoubleRightLeftRotation(AVLTree A){
	//将左子树右旋 
	A->right = SingleRightRotation(A->right);
	//再将当前节点左旋 
	return SingleLeftRotation(A);
} 

//左右旋 
AVLTree DoubleLeftRightRotation(AVLTree A){
	//将右子树左旋 
	A->left = SingleLeftRotation(A->left);
	//再将当前节点右旋 
	return SingleRightRotation(A);
} 

AVLTree Insert(AVLTree T, int X){
	if(!T){
		T = new AVLNode(X);
	}else if(X < T->data){
		T->left = Insert(T->left,X);
		if(GetHeight(T->left)- GetHeight(T->right) == 2){
			if(X < T->left->data){ //右旋 
				T = SingleRightRotation(T);
			}else{ //左右旋 
				T = DoubleLeftRightRotation(T);
			}
		}
	}else if(X > T->data){
		T->right = Insert(T->right,X);
		if(GetHeight(T->right)- GetHeight(T->left) == 2){
			if(X > T->right->data){ //左旋 
				T = SingleLeftRotation(T);
			}else{ //右左旋 
				T = DoubleRightLeftRotation(T);
			}
		}
	}
	//更新高度 
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
