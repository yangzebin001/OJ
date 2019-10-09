/*
 * @Date: 2019-09-16 15:25:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-16 15:47:17
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 10000+10;

double L[MAXN];
int N,K;

//每一段切成P长度
bool check(double p){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += (int)(L[i]/p);
    }
    return sum >= K;
    //如果sum比k大，说明分的太细，需要加长度
    //如果sum比k小，说明分的太粗，需要减长度
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++){
        scanf("%lf",&L[i]);
    }
    
    double l = 0, r = 1000000000000.0;
    for(int i = 0; i <= 100; i++){
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    // printf("%.2f\n",l);
    printf("%.2f\n",floor(l * 100) /100);
    return 0;
}