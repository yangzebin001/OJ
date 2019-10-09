/*
 * @Date: 2019-09-10 16:51:11
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-09 21:09:50
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 500005;
long long step = 0;

int arr[MAXN];
int t[MAXN];    

void mergesort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = l+r >> 1;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    int k = 0, i = l, j = mid+1;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]) t[k++] = arr[i++];
        // 此时左边数组的往后每个数与右边当前数都能组成逆序对
        else step += mid-i+1,t[k++] = arr[j++];
    }
    while(i <= mid) t[k++] = arr[i++];
    while(j <= r) t[k++] = arr[j++];

    for(i = 0, j = l; j <= r; i++,j++) arr[j] = t[i];
}

int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n){
        step = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]);
        }
        mergesort(arr,0,n-1);
        for(int i = 0; i < n; i++) printf("%d ",arr[i]);
        printf("\n");
        printf("%lld\n",step);
    }
    return 0;
}