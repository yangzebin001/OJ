/*
 * @Date: 2020-01-19 22:26:53
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-19 22:30:06
 */
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double a;
    double ans = 0;
    scanf("%lf",&a);
    for(int i = 1; i <= a; i++){
        ans += double(1.0/i);
    }
    printf("%.12f",ans);
    return 0;
}