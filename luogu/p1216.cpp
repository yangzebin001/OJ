/*
 * @Date: 2019-11-13 16:44:53
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-13 16:51:02
 */
#include<iostream>
#include<cstdio>

using namespace std;
const int MAXN = 1010;
int arr[MAXN][MAXN];
int main(){
    int N;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = N-1; i >= 1; i--){
        for(int j = 1; j <=i; j++){
            // if(j == 1) arr[i][j] += arr[i+1][j];
            arr[i][j] += max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
    printf("%d",arr[1][1]);
    return 0;
}