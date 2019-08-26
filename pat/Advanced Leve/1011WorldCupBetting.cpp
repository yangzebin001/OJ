/*
 * @Author: BeckoninGshy 
 * @Date: 2019-08-24 11:52:06 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2019-08-24 12:05:16
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    double ans = 0;
    double aaa,bbb,ccc;
    for(int i = 0; i < 3; i++){
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        double aa;
        int in = 0;
        if(a > b){
            if(a > c) in = 1, aa = a;
            else in = 3, aa = c;
        }else{
            if(b > c) in = 2, aa = b;
            else in = 3, aa = c;
        }
        if(in == 1){
            printf("W ");
        }else if(in == 2){
            printf("T ");
        }else if(in == 3){
            printf("L ");
        }
        if(i == 0){
            aaa = aa;
        }else if(i == 1){
            bbb = aa;
        }else{
            ccc = aa;
        }
    }
    printf("%.2lf\n",(aaa*bbb*ccc*0.65-1)*2);
    return 0;
}
