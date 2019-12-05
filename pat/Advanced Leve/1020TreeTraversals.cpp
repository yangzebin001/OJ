/*
 * @Date: 2019-11-03 19:13:24
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-04 15:01:54
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
const int MAXN = 40;

int inorder[MAXN],postorder[MAXN];
int N;
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(){};
    TreeNode(int i){val = i;left = right = NULL;}
};

TreeNode* dfs(int &index,int l,int r){
    if(l <= r){
        for(int i = l; i <= r; i++){
            if(inorder[i] == postorder[index]){
                TreeNode* root = new TreeNode();
                root->val = postorder[index--];
                root->right = dfs(index,i+1,r);
                root->left = dfs(index,l,i-1);
                // printf("%d  ",inorder[i]);
                return root;
            }
        }
    }
    return NULL;
}
void levelorder(TreeNode* root){
    queue<TreeNode*> q;
    int flag = 0;
    q.push(root);
    while(q.size()){
        TreeNode* t = q.front();
        q.pop();
        if(flag) printf(" ");
        printf("%d",t->val);
        if(flag == 0) flag = 1;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&postorder[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&inorder[i]);
    }
    int index = N-1;
    TreeNode* root = dfs(index,0,N-1);
    levelorder(root);
    return 0;
}