/*
 * @Date: 2020-02-12 17:37:12
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 18:03:41
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;

string A,B;
struct Node{
    int l = -1,r = -1;
    char data;
}node[28];
void preorder(int i){
    cout << node[i].data;
    if(node[i].l != -1){
        preorder(node[i].l);
    }
    if(node[i].r != -1){
        preorder(node[i].r);
    }
}
int getn(char c){
    if(islower(c)) return c-'a';
    return c-'A';
}
int notroot[26];
int vis[26];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A;
        int root = getn(A[0]);
        vis[root] = 1;
        node[root].data = A[0];
        if(A[1] != '*'){
            node[root].l = getn(A[1]);
            vis[getn(A[1])] = 1;
            notroot[getn(A[1])] = 1;
        }
        if(A[2] != '*'){
            node[root].r = getn(A[2]);
            vis[getn(A[2])] = 1;
            notroot[getn(A[2])] = 1;
        }
    }
    for(int i = 0; i < 26; i++){
        if(vis[i] && !notroot[i]){
            preorder(i);
            break;
        }
    }
    return 0;
}