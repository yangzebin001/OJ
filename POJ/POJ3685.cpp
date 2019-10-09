/*
 * @Date: 2019-10-05 16:59:48
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-05 18:07:41
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long int
using namespace std;
const LL INF = 0x3f3f3f3f3f;
const int E = (int)1e5;

LL N, M;
int T;

//每一列是单调的，所以求每一列中小于等于目标值的个数，与M比较。
LL f(LL i, LL j){
    return i * i + j * j + E*(i-j) + i*j;
}
bool check(LL x){
    LL cnt = 0;
    for(int i = 1; i <= N; i++){
        int l = 0, r = N;
        while(l < r){
            int mid = (l + r+1)>>1;
            if(f(mid,i) <= x) 
                l = mid;
            else 
                r = mid-1;
        }
        cnt += l;
    }
    return cnt >= M;
}


int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&N,&M);
        // printf("%d %lld %lld\n",T,N,M);
        LL l = -INF;
        LL r = INF;
        while(l < r){
            LL mid = (l+r)>>1;
            //所选数大于等于M
            if(check(mid)) 
                r = mid;
            else 
                l = mid+1;
        }
        printf("%lld\n",r);
    }
    return 0;
}
