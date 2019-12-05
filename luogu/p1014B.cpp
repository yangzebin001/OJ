/*
 * @Date: 2019-11-18 20:54:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-18 21:50:38
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e7+10;
struct node{
    int a,b;
}D[MAXN];
int N;
int main(){
    scanf("%d",&N);
    D[0].a = 1;
    D[0].b = 1;
    D[1].a = 1;
    D[1].b = 2;
    int flag = -1;//-1：向下 1：向上
    for(int i = 2; i < N; i++){
        if(D[i-1].b == 1 && flag == -1){
            D[i].b = 1;
            D[i].a = D[i-1].a+1;
            flag = -flag;
        }else if(D[i-1].a == 1 && flag == 1){
            D[i].a = 1;
            D[i].b = D[i-1].b+1;
            flag = -flag;
        }else{
            D[i].a = D[i-1].a-flag;
            D[i].b = D[i-1].b+flag;
        }
    }
    printf("%d/%d",D[N-1].a,D[N-1].b);
    return 0;
}