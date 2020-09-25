#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstdio>
using namespace std;
const int MAXN = 100;
int ind[MAXN];
int ind2[MAXN];
int n,m;
char now[4];
vector<int> edge[MAXN];
vector<int> ans;

set<int> have;
queue<int> q;

int topsort(){
    ans.clear();
    int t = 0,f = 0;
    for(int i = 0; i < n; i++){
        if(ind[i] == 0 && have.count(i)) {
            q.push(i);
            t++;    
        }
        ind2[i] = ind[i];
    }
    if(t > 1) f = 1;
    while(q.size()){
        t = 0;
        int now = q.front(); q.pop();
        ans.push_back(now);
        for(int i = 0; i < edge[now].size(); i++){
            int u = edge[now][i];
            ind2[u]--;
            if(ind2[u] == 0){
                q.push(u);
                t++;
            }
        }
        if(t > 1) f = 1; //目前队列内元素个数大于1
    }
    if(ans.size() != have.size()) return -1; //有结点没有到达，说明有环
    else if(ans.size() != n) return 1; //可以跑完拓扑排序，但个数不够，不确定
    else return f; //0可以确定顺序，其他尚未确定
}


int main(){
    cin >> n >> m;
    for(int k = 0; k < m; k++){
        scanf("%s",now);
        ind[now[2]-'A']++;
        edge[now[0]-'A'].push_back(now[2]-'A');
        have.insert(now[0]-'A');
        have.insert(now[2]-'A');
        while(q.size()) q.pop();
        
        int flag = topsort();
        if(flag == 0){
            cout <<"Sorted sequence determined after "<< k+1 <<" relations: ";
			for(int j=0;j<=n-1;j++)
			{
				cout<<(char)('A'+ ans[j]);
		    }
		    cout<<'.'<<endl;
		    return 0;
        }else if(flag == 1) continue;
        else{
            cout << "Inconsistency found after ";
        	cout<< k+1 <<" relations."<<endl;
        	return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined."<<endl;
    return 0;
}
