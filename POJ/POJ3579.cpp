/*
 * @Date: 2019-10-05 13:59:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-05 14:48:00
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 1e5+10;

int N;
int arr[MAXN];

bool check(int x){
    int cnt = 0;
    int M = N*(N-1)/2;
    M = (M+1)/2;
    for(int i = 0; i < N; i++){
        int l = i, r = N-1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(arr[mid] - arr[i] <= x) l = mid;
            else r = mid-1;
        }
        cnt += l-i;
        // arr[mid] - arr[i] <= x -----> arr[mid] <= arr[i]+x
        // 所以找arr[i]+x 的 upper_bound。
        // (upper_bound(arr,arr+N,arr[i]+x)-arr)-1 长度
        // (upper_bound(arr,arr+N,arr[i]+x)-arr)-i-1 //减去偏移量
        // cnt += (upper_bound(arr,arr+N,arr[i]+x)-arr)-i-1;
    }
    return cnt >= M;
}

int main(){
    freopen("in.txt","r",stdin); 
    while(scanf("%d",&N)!=EOF && N){
        for(int i = 0; i < N; i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+N);
        int l = 0, r = arr[N-1];
        //对结果进行二分
        while(l < r){
            int mid = l+r>>1;
            // 检查该结果是否大于等于总数的一半，
            if(check(mid)) r = mid;
            else l = mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}