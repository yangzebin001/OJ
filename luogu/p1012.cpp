/*
 * @Date: 2019-12-15 15:12:20
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-15 15:15:02
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int cmp(string a, string b){
    return a+b > b+a;
}
int main(){
    vector<string> v;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < N; i++){
        cout << v[i];
    }
    return 0;
}