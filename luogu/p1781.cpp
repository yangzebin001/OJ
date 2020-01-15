/*
 * @Date: 2020-01-13 22:18:46
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-01-13 22:39:08
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
struct node{
    int name;
    string num;
    node(int _n,string _m):name(_n),num(_m){};
};
int cmp(node& a, node& b){
    if(a.num.size() == b.num.size()) return a.num > b.num;
    return a.num.size() > b.num.size();
}
int main(){
    freopen("in.txt","r",stdin);
    int n;
    vector<node> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        v.push_back(node(i+1,a));
    }
    sort(v.begin(),v.end(),cmp);
    cout <<   v[0].name << endl << v[0].num << endl;
    return 0;
}