/*
 * @Date: 2019-09-20 20:09:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-20 20:46:39
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 50000+10;
int arr[MAXN];
int L,N,M;

bool check(int len){
    int pos = 0,cnt = 0;
    for(int i = 1; i <= N+1; i++){
        //如果间距比答案小，我们删除这个点。
        if(arr[i]-pos < len){
            cnt++;
        }else{
            pos = arr[i];
        }
    }
    return cnt <= M;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&L,&N,&M);
    for(int i = 1; i <= N; i++){
        scanf("%d",&arr[i]);
    }
    arr[N+1] = L;
    sort(arr,arr+N+2);
    int l = 0, r = L;
    while(l < r){
        int mid = (l+r+1)/2;
        //如果要删除的点大了，说明要缩小区间。
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    printf("%d",l);
    return 0;
}