/*
 * @Date: 2020-04-19 15:23:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-20 19:07:09
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

const int MAXN = 1010;//最大点数 
const int MAXM = 500100;//最大边数 n*(n-1)/2
int n;
int F[MAXN]; //并查集使用
int tol = 0;//边数，加边前赋值为0

struct node{
  int x,y,h;
}Node[1010];

//存储边的信息，起点，终点，权值
struct Edge{
	int u,v;
  double w;
}edge[MAXM]; 

double dis(node &a, node &b){
  return sqrt((double)(a.x-b.x) * (a.x-b.x) + (double)(a.y-b.y) * (a.y-b.y)) + (a.h-b.h) * (a.h-b.h);
}
//加边函数
void addedge(int u,int v){
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = dis(Node[u],Node[v]);
} 
//比较函数，排序用
bool cmp(Edge a,Edge b){
	return a.w < b.w;
} 
//查找元素所属集合。路径压缩版
int _find(int x){
	return F[x] == -1 ? x : F[x] = _find(F[x]);
}

//传入点数，返回最小生成树的权值，如果不连通返回-1
double Kruskal(int n){
	memset(F,-1,sizeof(F));
	//先对边排序
	sort(edge,edge+tol,cmp);
	int cnt = 0; //计算加入的边数。
	double ans = 0;
	//最多循环tol次
	for(int i = 0; i < tol; i++){
		int u = edge[i].u;
		int v = edge[i].v;
		double w = edge[i].w;
		int t1 = _find(u);
		int t2 = _find(v);
		//如果属于不同集合，合并
		if(t1 != t2){
			ans += w;
			F[t1] = t2;
			cnt++;
		}
		//共需合并n-1次，已经完成，可提前结束
		if(cnt == n-1) break;
	} 
	if(cnt < n-1) return -1;//不连通
	return ans; 
} 
int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d%d%d",&Node[i].x,&Node[i].y,&Node[i].h);
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      addedge(i,j);
    }
  }
  printf("%.2f",Kruskal(n));
  return 0;
}