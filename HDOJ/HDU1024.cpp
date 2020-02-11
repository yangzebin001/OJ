/*
 * @Date: 2020-01-24 10:42:12
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 11:37:00
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN =1e6+10;
int dp[MAXN],v[MAXN],numax[MAXN]; //保存上一层dp的最大值。
//dp[i][j] 表示将前i个数字分成j段的最大子段和。
//dp[i][j] = max(dp[i-1][j] + v[i], dp[k][j-1]+v[i](j <k <i))
/*
动态规划
决策：第i个数到底应该自成一组还是并到前面的那一组。
列写递推方程：dp[i,j] = max(dp[i-1, j] + v[i], max(dp[k, j-1]) + v[i]) (j < k < i)
解释：dp[i, j]表示前i个数分成j组的最优方案。max(dp[i-1, j] + v[i], max(dp[k, j-1]) + v[i])是一个决策过程。dp[i-1, j] + v[i]是与前面的数合并成一组。max(dp[k, j-1]) + v[i])是自成一组并且k的范围暗示了该组不与前一个数相连。当然相连的话自成一组也是没有意义的。
*/
//由于用二维数组存不下，所以要优化为一维数组，但是上述的数组依赖于二维，所以要进行转化
//转化为：
//dp[i][j] 表示分成i段前j个数字的最大子段和。
//dp[i][j] = max(dp[i-1][k](i-1 < k < j)(自成一段), dp[i][j-1](与前面合成一组)) + v[i];
//这样转移便只依赖于上一行的结果，
// dp[i-1][*] dp[i][*]
int main(){
    int k,n;
    while(cin >> k >> n){
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            dp[i] = numax[i] = 0;
        }
        dp[0] = numax[0] = 0;
        int lastmax = INT_MIN;
        for(int i = 1; i <= k; i++){
            lastmax = INT_MIN; //保存上一层dp的最大值
            for(int j = i; j <= n; j++){
            	//先利用之前的上一层最大值更新当前状态， 
                dp[j] = max(dp[j-1],numax[j-1]) + v[j];
                //再将j-1的最大值更新到上一层的最大值数组中， 将在i+1层循环中使用，当前循环不使用
                numax[j-1] = lastmax;
                //存储当前层的最大值 
                lastmax = max(lastmax,dp[j]); 
            }
        }
        cout << lastmax << endl;
    }
    return 0;
}