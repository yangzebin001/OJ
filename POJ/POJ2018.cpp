/*
 * @Date: 2019-09-19 20:06:07
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-19 20:14:52
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 100005;
int N,L;
int num[MAXN];
double sum[MAXN];

bool check(double mid){
    for(int i = 1; i <= N; i++) sum[i] = sum[i-1] + num[i] - mid;
    double minv = 2001;
    for(int i = L; i <= N; i++){
        minv = min(minv,sum[i-L]);
        //如果当前子段和大于等于零 即该区间大于等于平均值说可以选该值
        if(sum[i]-minv >= 0) return true;
    }
    return false;
}

int main(){
    scanf("%d%d",&N,&L);
    for(int i = 1; i <= N; i++)  scanf("%d", &num[i]);
    double l = 0, r = 2000;
    while(r - l > 1e-5){
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%d",(int)(r*1000));
    return 0;
}