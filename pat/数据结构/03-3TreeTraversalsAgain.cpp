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

int main(){
	int flag = 0;
	stack<int> s;
	int N;
	cin >> N;
	int root;
	int curr_node = 0;
	Tree* tree[N+4];
	for(int i = 0; i < 2* N; i++){
		string a;
		int data;
		cin >> a;
		
		if(a == "Push"){
			
			cin >> data; 
			tree[data] = new Tree(data);
			if(curr_node){
				tree[curr_node]->right = tree[data];
				curr_node = 0;
			}else if(!s.empty()){
				int father = s.top();
				tree[father]->left = tree[data];
			}
			s.push(data);
			 
			
		}else{
			curr_node = s.top();s.pop();
		}
		if(i == 0) root = data;
	}
	if(N){
		p(tree[root],flag);	
	}
	return 0;
} 
