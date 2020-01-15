/*
 * @Date: 2020-01-14 17:09:08
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 17:12:27
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int> > pq;
    int n,a,sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        pq.push(a);
    }
    while(pq.size()>1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a+b;
        sum += c;
        pq.push(c);
    }
    cout << sum;
    return 0;
}