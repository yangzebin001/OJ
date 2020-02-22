/*
 * @Date: 2020-02-13 18:26:12
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-13 19:19:56
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
// 如果没有b[i]这个属性的话就是明显的01背包问题。
// 现在考虑相邻的两个物品x,y。假设现在已经耗费p的时间，那么分别列出先做x,y的代价：
// a[x]-(p+c[x])*b[x]+a[y]-(p+c[x]+c[y])*b[y] (1)
// a[y]-(p+c[y])*b[y]+a[x]-(p+c[y]+c[x])*b[x] (2)
// 对这两个式子化简，得到(1)＞(2)的条件是c[x]*b[y]<c[y]*b[x].
// 发现只要满足这个条件的物品对(x,y)，x在y前的代价永远更优。
struct node{
    long long a,b,c;
}arr[55];
int cmp(node x, node y){
    return x.c * y.b < x.b * y.c;
}
long long dp[55][100010];
int n,m;
int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].a;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i].b;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i].c;
    }
    sort(arr+1,arr+1+n,cmp);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j-arr[i].c >= 0){
                dp[i][j] = max(dp[i][j],dp[i-1][j-arr[i].c]+(arr[i].a-j*arr[i].b));
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= 100000; i++){
        ans = max(ans,dp[n][i]);
    }
    cout << ans;
    return 0;
}