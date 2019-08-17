#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 2005;
struct Gang{
	string head;
	int personnum;
	int totalweight;
	Gang(string head,int personnum,int totalweight):head(head),personnum(personnum),totalweight(totalweight){
	}
	friend bool operator <(const Gang& a,const Gang& b){
		return a.head < b.head;
	}
};

int G[N][N];
map<string, int> m;
map<int,string> m1;
int index = 0;
int vis[N];
int weight[N];

void DFS(int i,int &head,int &totalweight,int &personnnum){
	personnnum++;	
	vis[i] = true;
	//记录最大点。 
	if(weight[i] > weight[head]){
		head = i;
	}
	for(int j = 0; j < index; j++){
		if(G[i][j] > 0){
			//统计边权
			totalweight += G[i][j];
			//计算过就没用了，删边，防止下次递归时重复计算 
			G[i][j] = G[j][i] = 0;
			if(!vis[j])
				DFS(j,head,totalweight,personnnum);
		}
	}
}


int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		string a,b;
		int w;
		cin >> a>> b >> w;
		if(m.find(a) == m.end()){
			m[a] = index;
			m1[index++] = a;
		}
		if(m.find(b) == m.end()){
			m[b] = index;
			m1[index++] = b;
		}
		weight[m[a]] += w;
		weight[m[b]] += w;
		G[m[a]][m[b]] += w;
		G[m[b]][m[a]] += w;
	}
	vector<Gang> ans;
	for(int i = 0; i < index; i++){
		if(!vis[i]){
			int head = i,totalweight = 0,personnum = 0;
			DFS(i,head,totalweight,personnum);
			if(personnum > 2 && totalweight > k){
				ans.push_back(Gang(m1[head],personnum,totalweight));
			} 
		}
			
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].head << " " << ans[i].personnum << endl;
	}
	return 0;
} 
