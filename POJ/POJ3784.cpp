/*
 * @Date: 2019-10-18 19:38:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-18 19:38:38
 */
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+10;
int arr[MAXN];
priority_queue<int> q1,q2;
void insert(int c){
    if(q1.empty() || c <= q1.top()){
        q1.push(c);
    }else{
        q2.push(-c);
    }
    if(q1.size() > q2.size()+1){
        q2.push(-q1.top());
        q1.pop();
    }
    if(q2.size() > q1.size()){
        q1.push(-q2.top());
        q2.pop();
    }
}
int getTop(){
    return q1.top();
}
int P,M,N;
int main(){
    scanf("%d",&P);
    while(P--){
        while(q1.size()) q1.pop();
        while(q2.size()) q2.pop();
        int cnt = 0;
        scanf("%d%d",&N,&M);
        printf("%d %d\n",N,(M+1)/2);
        for(int i = 1; i <= M; i++){
            int c;
            scanf("%d",&c);
            insert(c);
            if(i % 2 == 1){
                printf("%d ",getTop());
                cnt++;
            }
            if(cnt == 10) printf("\n"),cnt=0;
        }
        printf("\n");
    }
    return 0;
}
