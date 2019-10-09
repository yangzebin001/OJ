/*
 * @Date: 2019-10-05 20:39:30
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-05 21:49:18
 */
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long LL;
const int MAXN = 4000+10;

LL a[MAXN],b[MAXN],c[MAXN],d[MAXN],sum[MAXN*MAXN],N;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%lld",&N);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sum[i*N+j] = c[i]+d[j];
        }
    }
    sort(sum,sum+N*N);
    LL cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            LL aim = -(a[i]+b[j]); 
            cnt += upper_bound(sum,sum+N*N,aim)-lower_bound(sum,sum+N*N,aim);
        }
    }
    printf("%lld\n",cnt);
    return 0;
}