/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 14:15:08 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-10 14:15:08 
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 100010, M = 1100010;
int f[M];
int n;
int getf(int x){
    return f[x] == x ? x : f[x] = getf(f[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i <= M; i++){
        f[i] = i;
    }
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        x = getf(x);
        printf("%d ",x);
        f[x] = x+1;
    }

    return 0;
}