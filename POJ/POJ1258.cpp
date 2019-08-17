#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];

int prim(int N)
{
	memset(vis, false, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	int ans = 0;
	vis[0] = true;
	for (int i = 1; i < N; i++)
		dis[i] = G[0][i];
	for (int i = 1; i < N; i++)
	{
		int minc = INF;
		int p = -1;
		for (int j = 0; j < N; j++)
		{
			if (!vis[j] && minc > dis[j])
			{
				minc = dis[j];
				p = j;
			}
		}
		if (minc == INF)
			return -1;
		ans += minc;
		vis[p] = true;
		for (int j = 0; j < N; j++)
		{
			if (!vis[j] && dis[j] > G[p][j])
			{
				dis[j] = G[p][j];
			}
		}
	}
	return ans;
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		memset(G, INF, sizeof(G));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &G[i][j]);
				if (G[i][j] == 0)
					G[i][j] = INF;
			}
		}
		printf("%d\n", prim(N));
	};
	return 0;
}
