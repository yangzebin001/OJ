/*
 * @Date: 2019-09-16 16:20:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-16 16:32:11
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 100000+10;
int L[MAXN];

int N,K;

bool check(int d){
    int last = 0;
    for(int i = 1; i < K; i++){
        int cur = last;
        while(cur < N && L[cur]-L[last] < d){cur++;}
        if(cur == N) return false;
        last = cur;       
    }
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++){
        scanf("%d",&L[i]);
    }
    sort(L,L+N);
    int l = 0, r = 1000000001;
    while(l < r){
        int mid = l+r+1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    printf("%d",l);
    return 0;
}