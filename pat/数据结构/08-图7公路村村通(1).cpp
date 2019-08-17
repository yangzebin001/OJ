#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1010;//������ 
const int MAXM = 10000;//������
 
int F[MAXN]; //���鼯ʹ��

struct Edge{
	int u,v,w;
}edge[MAXM]; //�洢�ߵ���Ϣ����㣬�յ㣬Ȩֵ
int tol;//�������ӱ�ǰ��ֵΪ0

void addedge(int u,int v,int w){
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = w;
} 

bool cmp(Edge a,Edge b){
	return a.w < b.w;
} 

int find(int x){
	return F[x] == -1 ? x : F[x] = find(F[x]);
}

//���������������С��������Ȩֵ���������ͨ����-1
int Kruskal(int n){
	memset(F,-1,sizeof(F));
	sort(edge,edge+tol,cmp);
	int cnt = 0; //�������ı�����
	int ans = 0;
	for(int i = 0; i < tol; i++){
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if(t1 != t2){
			ans+= w;
			F[t1] = t2;
			cnt++;
		}
		if(cnt == n-1) break;
	} 
	if(cnt < n-1) return -1;//����ͨ
	return ans; 
} 

int main(){
	int N,M;
	cin >> N >> M;
	while(M--){
		int a, b, cost;
		cin >> a >> b >>cost;
		addedge(a,b,cost); 
	} 
	int ans = Kruskal(N);
	
	cout << ans;
	return 0;
} 
