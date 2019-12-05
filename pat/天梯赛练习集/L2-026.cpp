/*
 * @Date: 2019-11-07 15:52:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-07 16:01:56
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+10;
int arr[MAXN];
int d[MAXN];
int N;
int MAXn = 0;
int dfs(int t){
    if(arr[t] == -1){
        d[t] = 1;
        return 1;
    }
    if(d[arr[t]]) return d[t] = d[arr[t]]+1;
    return d[t] = dfs(arr[t])+1;
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 1; i <= N; i++){
        if(d[i] == 0) dfs(i);
    }
    for(int i = 1; i <= N; i++){
        MAXn = max(MAXn,d[i]);
    }
    printf("%d\n",MAXn);
    int flag = 0;
    for(int i = 1; i <= N; i++){
        
        if(d[i] == MAXn){
            if(flag == 1) printf(" ");
            printf("%d",i),flag = 1;
        }
    }

    return 0;
}