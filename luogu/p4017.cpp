#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 5010;
vector<int> edge[MAXN];
int ind[MAXN], w[MAXN], outd[MAXN];
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        //记录入度出度
        outd[a]++;
        ind[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        //入度为0是生产者
        if(ind[i] == 0) w[i] = 1, q.push(i);
    }
    int ans = 0;
    while(q.size()){
        int now = q.front(); q.pop();
        for(int i = 0; i < edge[now].size(); i++){
            int u = edge[now][i];
            if(--ind[u] == 0) q.push(u);
            w[u] = (w[u] + w[now]) % 80112002;
        }
    }
    //记录出度为0的点为消费者
    for(int i = 1; i <= n; i++){
        if(outd[i] == 0) ans = (ans + w[i]) % 80112002;
    }
    cout << ans << endl;
    return 0;
}