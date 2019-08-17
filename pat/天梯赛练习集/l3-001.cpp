#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 10005 

using namespace std;

int data[maxn];

int dfs(vector<int> &data, vector<int> &ans,int i, int cursum,int sum){
	if(i >= data.size()) return 0;
	if(cursum > sum) return 0;
	ans.push_back(data[i]);
	cursum += data[i];
	if(cursum == sum) return 1;
	if(dfs(data,ans,i+1,cursum,sum) == 1) return 1;
	else{
		ans.pop_back();
		cursum -= data[i];
		return dfs(data,ans,i+1,cursum,sum);
	}
}


int main(){
	int n,m,s = 0;
	cin >> n >> m;
	vector<int> v;
	vector<int> ans;
	for(int i = 0;i < n; i++){
		int t;
		cin >>t;
		v.push_back(t);	
		s += t;
	}
	if(m > s){
		cout << "No Solution" << endl;
		return 0;
	}
	sort(v.begin(),v.end());
	int f = 0;
	f = dfs(v,ans,0,0,m);
	if(f == 1){
		for(int i = 0; i < ans.size(); i++){
			if(i != 0) cout << " ";
			cout << ans[i];
		}
	}else{
		cout << "No Solution" << endl;
	}
	
	return 0;
}
