/*
 * @Date: 2020-02-05 12:32:54
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-05 12:46:20
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int left,right,data;
}Node[110];
int arr[110];
void dfs(int root, int& t){
    if(Node[root].left != -1){
        dfs(Node[root].left,t);
    }
    Node[root].data = arr[t++];
    if(Node[root].right != -1){
        dfs(Node[root].right,t);
    }
}
void levelt(int root){
    queue<int> q;
    q.push(root);
    int f = 0;
    while(q.size()){
        int now = q.front();q.pop();
        if(f) cout <<" ";
        cout << Node[now].data;
        f = 1;
        
        if(Node[now].left != -1){
            q.push(Node[now].left);
        }
        if(Node[now].right != -1){
            q.push(Node[now].right);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        int l,r;
        cin >> l >> r;
        Node[i].left = l;
        Node[i].right = r;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int t = 0;
    dfs(0,t);
    levelt(0);
    return 0;
}
 