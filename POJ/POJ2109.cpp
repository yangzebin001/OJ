/*
 * @Date: 2019-10-30 20:19:45
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-30 20:21:56
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    double n,p;
    while(scanf("%lf%lf",&n,&p) != EOF){
        printf("%.0f\n",pow(p,1.0/n));
    }

    return 0;
}