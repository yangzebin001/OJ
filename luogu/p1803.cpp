/*
 * @Date: 2020-02-12 17:29:54
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 17:34:04
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1e6+10;
struct node{
    int s,e;
}Node[MAXN];
int cmp(node a,node b){
    return a.e < b.e;
}
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Node[i].s >> Node[i].e;
    }
    sort(Node,Node+n,cmp);
    int laste = Node[0].e;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(Node[i].s >= laste){
            cnt++;
            laste = Node[i].e;
        }
    }
    cout << cnt;
    return 0;
}