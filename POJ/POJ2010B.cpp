/*
 * @Date: 2019-10-06 17:36:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-07 16:04:57
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;

PII arr[MAXN];
int M,N,S;
int lowa[MAXN],upa[MAXN];


int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&M,&N,&S);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
    }
    int half = M/2;
    sort(arr,arr+N);
    memset(lowa,INF,sizeof(lowa));
    memset(upa,INF,sizeof(upa));
    priority_queue<int> q;
    //确定以每个人为中位数， 比自己分数低的人的最小aid总和
    int total = 0;
    for(int i = 0; i < N; i++){
        if(q.size() == half) lowa[i] = total;
        total += arr[i].second;
        q.push(arr[i].second);
        if(q.size() > half){
            total -= q.top();
            q.pop();
        }
    }
    while(q.size()) q.pop();
    total = 0;
    //确定以每个人为中位数， 比自己分数高的人的最小aid总和
    for(int i = N-1; i >= 0; i--){
        if(q.size() == half) upa[i] = total;
        q.push(arr[i].second);
        total += arr[i].second;
        if(q.size() > half){
            total -= q.top();
            q.pop();
        }
    }
    int ans = -1;
    //从后往前寻找第一个满足条件的
    for(int i = N-1; i >= 0; i--){
        if(arr[i].second + lowa[i] + upa[i] <= S) {ans = arr[i].first;break;}
    }
    printf("%d\n",ans);
    return 0;
}