/*
 * @Date: 2020-01-13 22:18:46
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-01-13 22:27:50
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
    int name,num;
    node(int _n,int _m):name(_n),num(_m){};
};
int cmp(node& a, node& b){
    if(a.num == b.num) return a.name < b.name;
    return a.num > b.num;
}
int main(){
    freopen("in.txt","r",stdin);
    int n,m;
    vector<node> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(node(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    m = m * 1.5;
    cout << v[m-1].num << " ";
    int c = m;
    while(v[m-1].num == v[c-1].num) c++;
    cout << c-1 << endl;
    for(int i = 0; i < c-1; i++){
        cout << v[i].name << " " << v[i].num << endl;
    }
    return 0;
}