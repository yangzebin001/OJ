#include<iostream>
#include<string>
#include<stack>


using namespace std;
struct Tree{
	Tree* left;
	Tree* right;
	int data;
	Tree(){
	}
	Tree(int data):data(data){
		left = NULL;
		right = NULL;
	}
};

void p(Tree* t,int &flag){
	if(t){
		p(t->left,flag);
		p(t->right,flag);
		if(flag) printf(" ");
		printf("%d",t->data);
		flag = 1;
	}
}

//前序遍历的第一个字母在中序的位置， 
void solve(int preorder[], int preN, int inorder[],int inN, int postorder[], int postN){
	if(preN == 0) return;
	if(preN == 1){
		postorder[postN-1] = preorder[0];
		return;
	}
	int root = preorder[0];
	postorder[postN-1] = root;
	int i;
	for(i = 0; i < inN; i++){
		if(inorder[i] == root)break;
	}
	solve(preorder+1,i,inorder,i,postorder,i);
	solve(preorder+i+1,preN-1-i,inorder+i+1,inN-i-1,postorder+i,postN-1-i);
} 

int main(){
	int flag = 0;
	stack<int> s;
	int N;
	cin >> N;
	int preorder[N];
	int inorder[N];
	int postorder[N];
	string a;
	int k=0,j=0;
	for(int i = 0; i < 2*N; i++){
		cin >> a;
		if(a == "Push"){
			int data;
			cin >> data;
			s.push(data);
			preorder[k++] = data;
		}else{
			int data = s.top();
			s.pop();
			inorder[j++] = data;
		}
	}
	solve(preorder,N,inorder,N,postorder,N);
	for(int i = 0; i < N; i++){
		if(i != 0) cout << " ";
		cout << postorder[i];
	}
	
	return 0;
} 
