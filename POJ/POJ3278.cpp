#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int arr[MAXN];
int N,K;
void bfs(int i){
    queue<int> q;
    q.push(i);
    while(q.size()){
        int k = q.front(); q.pop();
        if(k == K) return;
        if(k-1 >= 0 && k-1 < MAXN && arr[k-1] == INF){
            arr[k-1] = arr[k]+1;
            q.push(k-1);
        }
        if(k+1 >= 0 && k+1 < MAXN && arr[k+1] == INF){
            arr[k+1] = arr[k]+1;
            q.push(k+1);
        }
        if(k*2 >= 0 && k*2 < MAXN && arr[k*2] == INF){
            arr[k*2] = arr[k]+1;
            q.push(k*2);
        }
    }
}
int main(){
    scanf("%d%d",&N,&K);
    memset(arr,INF,sizeof(arr));
    arr[N] = 0;
    if(K >= N){
        bfs(N);
        printf("%d",arr[K]);
    }else{
        printf("%d",N-K);
    }
    return 0;
}