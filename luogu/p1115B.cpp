/*
 * @Date: 2019-12-02 18:55:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-02 19:10:38
 */
#include<iostream>
#include<cstdio>
using namespace std;
int sum[200009];
int N,ans,minsum,t;
int main(){
    scanf("%d%d",&N,&sum[0]);
    ans = sum[0];
    //****minsum 一定要初始化为零。 如果a[0],a[1]是正数。正解是不减
    minsum = min(0,sum[0]);
    for(int i = 1; i < N; i++){
        scanf("%d",&t);
        sum[i] = sum[i-1]+t;
        ans = max(ans,sum[i]-minsum);
        minsum = min(minsum,sum[i]);
    }
    // ans = max(ans,sum[N-1]-minsum);
    printf("%d",ans);
    return 0;
}