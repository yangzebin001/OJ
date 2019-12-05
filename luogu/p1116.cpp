/*
 * @Date: 2019-11-18 17:59:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-18 22:00:27
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e4+10;
int cnt = 0,len;
int a[MAXN];
//逆序对  a[i] > a[i+1] 冒泡排序 n2 1ms 1e9 1e8
// 归并排序 nlogn    //通用求逆序对
void sort(int a[],int len){
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(a[i] > a[j]){
                swap(a[i],a[j]);
                cnt++;
            }
        }
    }
}

int main(){
    scanf("%d",&len);
    for(int i = 0; i < len; i++) scanf("%d",&a[i]);
    sort(a,len);
    printf("%d",cnt);
    return 0;
}