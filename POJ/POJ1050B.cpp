#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[200][200];
int ans = -200;
int n;

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &t);
            //前i行，第j列的总和。
            dp[i][j] = dp[i - 1][j] + t;
        }
    }

    for (int i = 1; i <= n; i++)
    { //行末尾
        for (int k = 1; k <= i; k++)
        { //行开头
            int maxsum = 0;
            // 把行区间中每一列看做一个数，求该数组中的最大子段和。
            for (int j = 1; j <= n; j++)
            {
                if (maxsum < 0)
                {
                    maxsum = 0;
                }
                //当前行区间内每一列的总和。
                maxsum += dp[i][j] - dp[k - 1][j];
                ans = max(ans, maxsum);
            }
        }
    }

    printf("%d", ans);
    return 0;
}
