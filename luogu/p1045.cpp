/*
 * @Date: 2020-02-15 20:56:18
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-14 20:44:26
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int P;
int res[1010],sav[1010],f[1010];
//10**n 有n+1位
//2 = 10**(log10(2))
//x = (10**(log10(2)))**p
//所以位数为：n = log10(2)*p+1
void work1(){
    memset(sav,0,sizeof(sav));
    for(int i = 0; i < 500; i++){
        for(int j = 0; j < 500; j++){
            sav[i+j] += f[i]*f[j];
        }
    }
    for(int i = 0; i < 500; i++){
        sav[i+1] += sav[i]/10;
        sav[i] %= 10;
    }
    memcpy(f,sav,sizeof(f));
}
void work2(){
    memset(sav,0,sizeof(sav));
    for(int i = 0; i < 500; i++){
        for(int j = 0; j < 500; j++){
            sav[i+j] += res[i]*f[j];
        }
    }
    for(int i = 0; i < 500; i++){
        sav[i+1] += sav[i]/10;
        sav[i] %= 10;
    }
    memcpy(res,sav,sizeof(res));
}
int main(){
    scanf("%d",&P);
    printf("%d\n",(int)(log10(2)*P+1));
    res[0] = 1;
    f[0] = 2;
    while(P){
        if(P&1) work2();
        P>>=1;
        work1();
    }
    res[0]--; //末尾不可能为0所以不会有退位
    for(int i = 500; i > 0; i--){
        if(i != 500 && i % 50 == 0)
            printf("\n");
        printf("%d",res[i-1]);
    }
    return 0;
}