/*
 * @Date: 2020-02-12 17:37:12
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 17:49:55
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

string A,B;
struct Node{
    int l = -1,r = -1;
    char data;
}node[10];
int dfs(string a, string b, int &bi, int l,int r){
    if(l > r) return -1;
    char c = b[bi];
    for(int i = l; i <= r; i++){
        if(a[i] == c){
            bi--;
            node[i].data = c;
            node[i].r = dfs(a,b,bi,i+1,r);
            node[i].l = dfs(a,b,bi,l,i-1);
            return i;
        }
    }
    return -1;
}
void preorder(int i){
    cout << node[i].data;
    if(node[i].l != -1){
        preorder(node[i].l);
    }
    if(node[i].r != -1){
        preorder(node[i].r);
    }
}
int main(){
    cin >> A >> B;
    int q = B.size()-1;
    int root = dfs(A,B,q,0,A.size()-1);
    preorder(root);
    return 0;
}