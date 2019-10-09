/*
 * @Date: 2019-09-20 20:47:51
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-20 21:14:04
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1e5+10;
int N,M;
int arr[MAXN];

bool check(int l){
    int i = 0;
    int cnt = 0;
    while(i < N){
        int sum = arr[i];
        while(i < N && sum <= l){
            sum += arr[++i];
        }
        //如果当前的单个也算大了，说明这个值小了，返回0
        if(sum == arr[i]) return 0;
        cnt++;
    }
    return cnt <= M;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++) scanf("%d",&arr[i]);
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l+r) >> 1;
        //预测的可以，拿更小的试一试
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d",l);
    return 0;
}