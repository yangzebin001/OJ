//#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string> 

using namespace std;
typedef int ElementType;

typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

struct TreeNode{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
}; 

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T); 
Position FindMax(SearchTree T); 

SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);

void Print(SearchTree T, int n);

void Print(SearchTree T, int n){
	if(T != NULL){
		n++;
		Print(T->Left,n);
		int i;
		for(i = 2; i < n;i++){
			printf("\t");
		}
		printf("%d\n",T->Element);
		
		Print(T->Right,n);
		
	} 
}

SearchTree MakeEmpty(SearchTree T){
	if(T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position FindParent(ElementType X, SearchTree T, SearchTree Parent){
	if(T == NULL){
		return NULL;
	}
	if(X < T->Element){
		return FindParent(X, T->Left, T); 
	}else if(X > T->Element){
		return FindParent(X, T->Right, T);
	}else{
		return Parent;
	}
}

Position Find(ElementType X, SearchTree T){
	if(T == NULL){
		return NULL;
	}
	if(X < T->Element){
		return Find(X,T->Left); 
	}else if(X > T->Element){
		return Find(X, T->Right);
	}else{
		return T;
	}
}


Position FindMin(SearchTree T){
	if(T != NULL){
		while(T->Left != NULL)
			T = T->Left;
	}
	return T;
	
}

Position FindMax(SearchTree T){
	if(T == NULL){
		return NULL;
	}
	if(T->Right == NULL){
		return T;
	}else {
		return FindMax(T->Right);
	}
	
}

SearchTree Insert(ElementType X, SearchTree T){
	
	//if tree is null create and return a one-node tree.
	if(T == NULL){
		
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(T == NULL){
			printf("create tree failed!");
			return 0;
			
		}else{
			T->Element = X;
			T->Left = T->Right =  NULL;
		}
	}else if(X < T->Element){ //X < T's Emement ?    and carry X to T's nextNode.
		T->Left = Insert(X, T->Left);
	}else if(X > T->Element){
		T->Right = Insert(X, T->Right);
	}
	
	//Else X is in the tree already, we'll do nothing.
	
	//return created Node.
	return T;
}

SearchTree Delete(ElementType X, SearchTree T){
	//create a temp treenode.
	Position TmpCell;
	
	if(T == NULL){
		printf("Element not found");
		return 0;
	}else if(X < T->Element){
		T->Left = Delete(X, T->Left);
	}else if(X > T->Element){
		T->Right = Delete(X, T->Right);
	}	
	else if(T->Left && T->Right){ //Two children
		// replace with smallest in right subtree
		
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		
		
		T->Right = Delete(T->Element, T->Right);
	}else{   //one or zero children
		TmpCell = T;
		if(T->Left == NULL){  //also handles 0 children
			
			T = T->Right; 
		}else if(T->Right == NULL){
			T = T->Left; 
		}
		free(TmpCell);
	}
	
	return T;
}





int main(){
	string root = "root";
	string siblings = "siblings";
	string level = "level";
	string parent = "parent";
	string left  = "left";
	string right = "right";
	
	SearchTree t = NULL;
	int n,i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		int q;
		scanf("%d", &q);
		t = Insert(q,t);
	}
	scanf("%d",&n);
	getchar(); 
	string a;
	for(int i = 0; i < n; i++){
		a = "";
		getline(cin,a);
		cout << a;
		if(a.find(root) !=std::string::npos){
			if(t->Element == atoi( a.c_str() ) ){
				cout << "Yes"<<endl;
			}else{
				cout << "No" <<endl;
			}
		}else if(a.find(parent) != std::string::npos){
			int child, pare;
			child = atoi( a.c_str() );
			string b = a.substr(a.find(parent));
			pare = atoi( b.c_str() );
			cout << b <<endl;
			cout << child << pare;
		}
		
		
		
	}
	
//	Position a;
//	a = Find(2,t);
//	cout << a->Left->Element;
	
//	a = FindParent(4,t, NULL);
//	cout << a->Element;
	return 0;
}
