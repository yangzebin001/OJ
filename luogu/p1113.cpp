#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1e4+10;
vector<int> edge[MAXN];
queue<int> q;
int indegree[MAXN], ans[MAXN], w[MAXN];
int n,a,b,c;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        //该点的权值
        w[a] = b;
        while(c != 0){
            //添加边
            edge[c].push_back(a);
            //入度++
            indegree[a]++;
            cin >> c;
        }
    }

    for(int i = 1; i <= n; i++){
        //入度为零的点全部放入队列
        if(indegree[i] == 0){
            q.push(i);
            ans[i] = w[i];
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < edge[now].size(); i++){
            int u = edge[now][i];
            indegree[u]--;
            //入度为0，前置任务已全部完成，添加到队列中
            if(indegree[u] == 0) q.push(u);
            //更新最大权值
            ans[u] = max(ans[u], ans[now]+w[u]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, ans[i]);
    cout << res << endl;
    return 0;
}