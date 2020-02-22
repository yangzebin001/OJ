/*
 * @Date: 2020-02-12 18:37:54
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 19:34:58
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e6+10;
struct node{
    int l = -1, r = -1, data;
}Node[MAXN];
int n;
int ans = 1;
bool isSymmetric(int i,int j){
    if(i == -1 && j == -1) return true;
    if(i == -1 || j == -1) return false;
    return Node[i].data == Node[j].data && isSymmetric(Node[i].l,Node[j].r) && isSymmetric(Node[i].r,Node[j].l);
}
int dfs(int i){
    if(i == -1) return 0;
    int t1 = dfs(Node[i].l);
    int t2 = dfs(Node[i].r);
    if(isSymmetric(i,i))
        ans = max(ans,t1+t2+1);
    return t1+t2+1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> Node[i].data;
    }
    for(int i = 1; i <= n; i++){
        int l,r;
        cin >> l >>r;
        Node[i].l = l;
        Node[i].r = r;
    }
    dfs(1);
    cout <<ans;
    return 0;
}