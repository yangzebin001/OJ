/*
 * @Date: 2019-08-26 09:29:19
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 10:04:35
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int cmp(int a,int b){
    return a > b;
}

int triangle[15][15];
int m[15];
int N,T;
int main(){
    scanf("%d%d",&N,&T);
    for(int i = 1; i <= N; i++) m[i] = i;
    for(int i = 1; i <= N; i++) triangle[i][1] = triangle[i][i] = 1;
    for(int i = 3; i <= N; i++){
        for(int j = 2; j <= (i+1)/2; j++){
            triangle[i][j] = triangle[i][i+1-j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    do{
        int sum = 0;
        for(int i = 1; i <= N; i++){
            sum += m[i]*triangle[N][i];
            if(sum > T){
                sort(m+i,m+N+1,cmp);
                break;
            }
        }
        if(sum == T){
            for(int i = 1; i <= N; i++){
                if(i != 1) printf(" ");
                printf("%d",m[i]);
            }
            break;
        }

    }while(next_permutation(m+1,m+1+N));

    return 0;
}