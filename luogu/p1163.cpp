#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a,b,c;
int main(){
    cin >> a >>b >>c;
    double l = 0, r = 10;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2;
        double d = a;
        //利率按月累积
        for(int i = 1; i <= c; i++){
            d = d*(1+mid)-b;
        }
        if(d >= 0) r = mid;
        else l = mid;
    }
    printf("%.1f", l*100);
    return 0;
}