/*
 * @Date: 2020-02-12 13:53:42
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 14:10:33
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int cost,num;
    node(){};
    node(int _cost, int _num):cost(_cost),num(_num){};
}Node[5010];
int cmp(node a, node b){
    return a.cost < b.cost;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> Node[i].cost >> Node[i].num;
    }
    sort(Node,Node+m,cmp);
    long long ans = 0;
    for(int i = 0; i < m && n; i++){
        if(n <= Node[i].num){
            ans += n*Node[i].cost;
            n = 0;
        }else{
            n -= Node[i].num;
            ans += Node[i].num*Node[i].cost;
        }
    }
    cout << ans;
    return 0;
}