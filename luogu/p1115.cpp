/*
 * @Date: 2019-12-02 18:06:22
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-02 18:50:43
 */
#include<iostream>
#include<cstdio>
using namespace std;
int N;
int main(){
    scanf("%d",&N);
    int a,sum,ans;
    scanf("%d",&a);
    ans = sum = a;
    for(int i = 1; i < N; i++){
        scanf("%d",&a);
        sum = max(a,sum+a);
        ans = max(ans,sum);
    }
    printf("%d",ans);
    return 0;
}