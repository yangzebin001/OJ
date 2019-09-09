/*
 * @Date: 2019-08-26 20:56:45
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 20:56:45
 */
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 2005;

int f[maxn];
char p[maxn][10];
struct node
{
    int u, v, len;
    friend bool operator < (node a, node b)
    {
        return a.len > b.len;
    }
};

int Len(char a[], char b[])
{
    int sum = 0;
    for(int i=0; a[i]; i++)
        if(a[i] != b[i])sum++;

    return sum;
}
int Find(int x)
{
    if(f[x] != x)
        f[x] = Find(f[x]);
    return f[x];
}
int main()
{
    int N;

    while(scanf("%d", &N) != EOF && N)
    {
        node s;
        priority_queue<node> Q;

        for(s.u=1; s.u<=N; s.u++)
        {
            f[s.u] = s.u;
            scanf("%s", p[s.u]);
            for(s.v=1; s.v<s.u; s.v++)
            {
                s.len = Len(p[s.u], p[s.v]);
                Q.push(s);
            }
        }
        int ans = 0, t=0;//如果已经链接了N-1条边就可以结束了
        while(Q.size() && t < N-1)
        {
            s = Q.top();Q.pop();
            int u = Find(s.u), v = Find(s.v);

            if(u != v)
            {
                t++;
                f[v] = u;
                ans += s.len;
            }
        }

        printf("The highest possible quality is 1/%d.\n", ans);
    }

    return 0;
}