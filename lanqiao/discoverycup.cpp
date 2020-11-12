#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int n,a,b,cnt;
int in[maxn];
vector<int>e[maxn];
queue<int>q;
bool vis[maxn];
void topo()
{
	for(int i=1;i<=n;++i)
	{
		if(in[i]==1)
		{
			q.push(i);
			vis[i]=1; 
		} 
	}
	while(!q.empty())
	{
		int t=q.front(); 
		q.pop();
		int len=e[t].size();
		for(int i=0;i<len;++i)
		{
			--in[e[t][i]];
			if((in[e[t][i]])==1)
			{
				q.push(e[t][i]);
				vis[e[t][i]]=1;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		e[a].push_back(b);in[a]++;
		e[b].push_back(a);in[b]++;
	}
	for(int i = 1; i <= n; i++){
		cout << in[i] << " ";
	}
	cout << endl;
	topo();
	for(int i=1;i<=n;++i)
	if(!vis[i])
	{
		if(!cnt)printf("%d",i);
		else printf(" %d",i);
		cnt++;
	}
	puts("");
	return 0;
} 