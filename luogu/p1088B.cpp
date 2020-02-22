/*
 * @Date: 2020-02-13 22:16:06
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-13 22:37:31
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int arr[10010];
void next(){
    int i;
    //找到需要逆序的位置。
    for(i = n-1; i >= 0; i--){
        if(arr[i] < arr[i+1]) break;
    }
    if(i >= 0){
        int j = n-1;
        // a[i−1] 右边的所有数字都已按降序排序。
        //找到第一个大于该点的位置
        while(j>=0 && arr[j] <= arr[i]){
            j--;
        }
        //交换
        if(j >= 0)
            swap(arr[i],arr[j]);
    }
    //把其后的整个数组变为升序
    reverse(arr+i+1,arr+n);
    
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >>arr[i];
    for(int i = 0; i < m; i++) {
        next();
        for(int j = 0; j < n; j++) cout << arr[j] <<" ";
    }
    return 0;
}