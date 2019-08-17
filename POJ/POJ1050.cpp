#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m[200][200];
int dp[200][200];
int ans = -200;
int n;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + m[i][j] - dp[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                for (int r = j; r <= n; r++)
                {
                    ans = max(ans, dp[k][r] - dp[i - 1][r] - dp[k][j - 1] + dp[i - 1][j - 1]);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
