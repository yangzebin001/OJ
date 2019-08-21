#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef unsigned long long ULL;
int n;
void bfs(int n){
    int ans = 1;
    queue<ULL> q;
    while(!q.empty()) q.pop();
    q.push(ans);
    while(q.size()){
        ULL i = q.front();q.pop();
        if(i % n == 0){
            printf("%llu\n",i);
            return;
        }
        q.push(i*10);
        q.push(i*10+1);
    }
}

int main(){
    while(~scanf("%d",&n) && n){
        bfs(n);
    }
    return 0;
}