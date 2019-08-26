#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 35;
int postorder[MAXN];
int inorder[MAXN];
vector<int> preorder;

int n;
int find_num(int num){
    for(int i = 0; i < n; i++){
        if(inorder[i] == num) return i;
    }
    return -1;
}

void dfs(int *postder,int *inorder,int n){
    if(n <= 0) return;
    int mid;
    for(int i = 0; i < n; i++){
        if(inorder[i] == postorder[n-1]){
            mid = i;
            break;
        }
    }
    printf(" %d",postder[n-1]);
    dfs(postder,inorder,mid);
    dfs(postder+mid,inorder+mid+1,n-1-mid);

}


int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> postorder[i];
    }
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }
    cout << "Preorder:";
    dfs(postorder,inorder,n);
    
    
    return 0;
}