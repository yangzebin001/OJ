#include<iostream>
#include<string>
#include<cstdio>

using namespace std;
struct node{
    string S;
    char t;
    node * left;
    node * right;
    node(string _S,char _t):S(_S),t(_t){};
    node(){};
};
char judge(string c){
    int a = 0;
    for(int i = 0; i < c.size(); i++){
        if(c[i] == '1') a++;
    }
    if(a == 0) return 'B';
    if(a == c.size()) return 'I';
    return 'F';
}
node* dfs(string s){
    if(!s.size()) return NULL;
    char c = judge(s);
    node* root = new node(s,c);
    root->left = dfs(s.substr(0,s.size()/2));
    root->right = dfs(s.substr(s.size()/2,s.size()/2));
    return root;
}
void postval(node* root){
    if(!root) return;
    postval(root->left);
    postval(root->right);
    printf("%c",root->t);
}
int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    // cout << s.substr(0,1/2) << " " << s.substr(s.size()/2) << endl;
    node* root = dfs(s);
    postval(root);
    return 0;
}