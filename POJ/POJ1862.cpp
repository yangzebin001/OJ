/*
 * @Date: 2019-10-26 16:58:48
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-26 17:11:20
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    priority_queue<double> q;
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        double a;
        scanf("%lf",&a);
        q.push(a);
    }
    while(q.size() > 1){
        double a = q.top(); q.pop();
        double b = q.top(); q.pop();
        q.push(2 * sqrt(a*b));
    }
    printf("%.3f\n",q.top());
    return 0;
}