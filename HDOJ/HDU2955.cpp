/*
 * @Date: 2019-11-21 19:28:58
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-21 20:24:14
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 11000;
double dp[MAXN]; //以钱为下标，安全偷钱的概率为值
int T,N,V[MAXN],sum;
double W[MAXN],P;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%lf%d",&P,&N);
        sum = 0;
        P = 1-P;//最大安全概率
        memset(dp,0,sizeof(dp));
        dp[0] = 1;//***！！！*** 一定要初始化当没有钱时概率为1。每次做的也是乘概率的运算。
        for(int i = 1; i <= N; i++){
            scanf("%d%lf",&V[i],&W[i]);
            W[i] = 1-W[i];
            sum += V[i];
        }
        for(int i = 1; i <= N; i++){
            for(int j = sum; j >= V[i]; j--){
                dp[j] = max(dp[j],dp[j-V[i]]*W[i]);
            }
        }
        
        for(int i = sum; i >= 0; i--){
            if(dp[i] >= P){ //概率越大，说明越安全，则说明钱越少。
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}