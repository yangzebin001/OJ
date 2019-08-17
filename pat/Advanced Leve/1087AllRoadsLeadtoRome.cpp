#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 500;
const int INF = 0x3f3f3f3f;
int G[MAXN][MAXN];

int vis[MAXN];
int dis[MAXN];
int W[MAXN];
vector<int> paths[MAXN];

map<string, int> ctoi;
map<int, string> itoc; 
int rom; 
void Init(int N){
	for(int i = 0; i < N; i++){
		paths[i].clear();
	}
}

void Dijkstra(int s, int N){
	for(int i = 0; i < N; i++){
		vis[i] = false;
		dis[i] = i == s ? 0:INF;
	}
	for(int i = 0; i < N; i++){
		int Min = INF;
		int k = -1;
		for(int j = 0; j < N; j++){
			if(!vis[j] && Min > dis[j]){
				Min = dis[j];
				k = j;
			}
		}
		if(k == -1)break;
		vis[k] = true;
		for(int j = 0; j < N; j++){
			if(!vis[j] && G[k][j] != INF){
				if(dis[j] > dis[k] + G[k][j]){
					dis[j] = dis[k] + G[k][j];
					paths[j].clear();
					paths[j].push_back(k);
				}else if(dis[j] == dis[k] + G[k][j]){
					paths[j].push_back(k);
				}
			}
		}
	} 
}

void calpath(vector<vector<int> > &ans,vector<int> p,int j){
	if(j == 0){
		ans.push_back(p);
		return;
	}
	for(int i = 0; i < paths[j].size(); i++){
		p.push_back(paths[j][i]);
		calminpath(ans,p,paths[j][i]);
		p.pop_back();
	}
}

void showpath(vector<int> p){
	stack<int> s;
	for(int i = 0; i < p.size(); i++){
		s.push(p[i]);
	}
	while(!s.empty()){
		cout << itoc[s.top()] << "->";
		s.pop();
	}
	cout << itoc[rom];
}
int calH(vector<int> p){
	int ans = W[rom];
	for(int i = 0; i < p.size(); i++){
		ans += W[p[i]];
	}
	return ans;
}

int main(){
	memset(G,INF,sizeof(G));
	int N,M;
	string S;
	cin >> N >> M >>S;
	Init(N);
	ctoi[S] = 0;
	itoc[0] = S;
	W[0] = 0;
	for(int i = 1; i < N; i++){
		string a;
		int w;
		cin >> a >> w;
		ctoi[a] = i;
		itoc[i] = a;
		W[i] = w;
		if(a == "ROM") rom = i;
	}
	while(M--){
		string a,b;
		int d;
		cin >>a >>b >> d;
		G[ctoi[a]][ctoi[b]] = d;
		G[ctoi[b]][ctoi[a]] = d;
	}
	Dijkstra(ctoi[S],N);
	
	int cost = dis[rom];
	int happiness = -13221421;
	vector<vector<int> > ans;
	vector<int> p;
	calminpath(ans,p,rom);
	p.clear();
    int toendpathcnt = ans.size(); 
	for(int i = 0; i < ans.size(); i++){
		int Hi = calH(ans[i]);
		if(Hi > happiness){
			happiness = Hi;
			p = ans[i];
		}else if(Hi == happiness){
			if(ans[i].size() < p.size()) p = ans[i];
		}
	}
//	for(int i = 0; i < p.size(); i++){
//		cout << p[i] << " ";
//	}
//	cout << endl;
	cout << toendpathcnt << " "<<cost << " " << happiness << " " << happiness/p.size() << endl;
	showpath(p);
	return 0;
}
