#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<map>
#include<algorithm> 
using namespace std;

int re[20010][20010];

int desMax(int i,int N){
	int maxi = 0;
	for(int j = 1; j <= N;j++){
		if(re[i][j] > re[i][maxi]) maxi = j;
	}
	re[i][maxi] = 0;
	re[maxi][i] = 0;
	return maxi;
}

map<int, pair<int,int> > G;
int visited[20010];

int main(){
	vector<int> v1,v2;
	int v1max = 0,v2max = 0;
	int N,t;
	cin >> N >>t;
	while(t--){
		int a,b,c;
		cin >>a>>b>>c;
		pair<int,int> d(a,b);
		re[a][b] = c;
		re[b][a] = c;
		G[c] = d;
	}
	map<int, pair<int,int> >::iterator Gp;
	Gp = G.end();
	for(--Gp;;Gp--){
		int a = Gp->second.first;
		int b = Gp->second.second;
		if(v1.size() == 0){
			v1.push_back(a);
			v2.push_back(b);
			visited[a] = 1;
			visited[b] = 1;
		}else{
			//为两端点寻找合适的位置 
			if(visited[a] && visited[b]) continue;
			if(visited[a]){
				if(find(v1.begin(),v1.end(),a) != v1.end()){
					v2.push_back(b);
					
				}else if(find(v1.begin(),v1.end(),a) != v1.end()){
					v1.push_back(b);
				} 
				visited[b] = 1;
			}else if(visited[b]){
				if(find(v1.begin(),v1.end(),b) != v1.end()){
					v2.push_back(a);
				}else if(find(v2.begin(),v2.end(),b) != v1.end()){
					v1.push_back(a);
				} 
				visited[a] = 1;
			}else{
				//先看第一个人在v1,v2的最高值
				int amaxInV1 = 0,amaxInV2 = 0;
				for(int i = 0; i < v1.size(); i++){
					if(re[a][v1[i]] > amaxInV1) amaxInV1 = re[a][v1[i]];
				} 
				if(amaxInV1 < v1max) amaxInV1 = v1max;
				//a在v2中。 
				for(int i = 0; i < v2.size(); i++){
					if(re[a][v2[i]] > amaxInV2) amaxInV2 = re[a][v2[i]];
				} 
				if(amaxInV2 < v2max) amaxInV2 = v2max;
				
				
				//再看第二个人在v1,v2的最高值
				int bmaxInV1 = 0,bmaxInV2 = 0;
				for(int i = 0; i < v1.size(); i++){
					if(re[b][v1[i]] > bmaxInV1) bmaxInV1 = re[b][v1[i]];
				} 
				if(bmaxInV1 < v1max) bmaxInV1 = v1max;
				//a在v2中。 
				for(int i = 0; i < v2.size(); i++){
					if(re[b][v2[i]] > bmaxInV2) bmaxInV2 = re[b][v2[i]];
				} 
				if(bmaxInV2 < v2max) bmaxInV2 = v2max;
				
				//如果a在v1，b在v2的代价小于 a在v2，b在v1的代价
				if(max(amaxInV1,bmaxInV2) < max(amaxInV2,bmaxInV1)){
					v1.push_back(a);
					v2.push_back(b);
					v1max = amaxInV1;
					v2max = bmaxInV2;
				}else{
					v1.push_back(b);
					v2.push_back(a);
					v1max = bmaxInV1;
					v2max = amaxInV2;
				}
				visited[a] = 1;
				visited[b] = 1;
			}
		}
		
		if(Gp == G.begin())break;
		int flag = 0;
		for(int i = 1; i <= N; i++){
			if(!visited[i]) flag = 1;
		}
		if(!flag)break;
	}
	cout << max(v1max,v2max) << endl;
	    
}
