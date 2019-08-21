#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAXN = 20;
const int INF = 0x3f3f3f3f;

int m[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
int ans = INF;

struct node{
    int x;
    int y;
    int step;
}w[150];
int bfs(node a,node b)
{
    queue<node> q;
    q.push(a);
    q.push(b);
    vis[a.x][a.y] = 1;
    vis[b.x][b.y] = 1;
    int cnt = 0;
    while (q.size())
    {
        a = q.front();
        q.pop();
        cnt = max(cnt,a.step);
        for (int i = 0; i < 4; i++)
        {
            b.x = a.x + dx[i];
            b.y = a.y + dy[i];
            b.step = a.step+1;
            if (b.x >= 0 && b.x < N && b.y >= 0 && b.y < M && m[b.x][b.y] && !vis[b.x][b.y])
            {
                q.push(b);
                vis[b.x][b.y] = 1;
            }
        }
    }
    return cnt;
}

bool isRest()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (m[i][j] && !vis[i][j])
                return true;
        }
    }
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d%d", &N, &M);
        memset(m, 0, sizeof(m));
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            char aa[MAXN];
            scanf("%s", aa);

            for (int j = 0; j < M; j++)
            {
                if (aa[j] == '#'){

                    m[i][j] = 1;
                    w[sum].x = i;
                    w[sum].y = j;
                    w[sum].step = 0;
                    sum++;
                }
            }
        }
        if (sum < 2)
        {
            printf("Case %d: %d\n", t, 0);
            continue;
        }

        ans = INF;
        for (int i = 0; i < sum; i++)
        {
            for (int j = i; j < sum; j++)
            {
                memset(vis, 0, sizeof(vis));
                int c = bfs(w[i],w[j]);
                if (!isRest())
                    ans = min(ans, c);
                 
            }
        }
        //连通分量大于2
        if (ans != INF)
            printf("Case %d: %d\n", t, ans);
        else
            printf("Case %d: -1\n", t);
    }

    return 0;
}