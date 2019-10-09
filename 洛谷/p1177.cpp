/*
 * @Date: 2019-09-16 17:27:20
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-16 17:32:44
 */
#include<iostream>
using namespace std;
const int MAXN =100000+10;

int arr[MAXN];
int t[MAXN];
int N;

void qsort(int q[], int l, int r)
{
    if(l >= r) return;
    int i = l-1, j = r+1, x = q[l+r>>1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    qsort(q,l,j),qsort(q,j+1,r);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    qsort(arr,0,N-1);
    for(int i = 0; i < N; i++) cout << arr[i] << " ";
    return 0;
}