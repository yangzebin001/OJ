#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
    int l = -1, r = -1;
}node[110];


int getDepth(int root){
    if(root == -1) return 0;
    return max(getDepth(node[root].l), getDepth(node[root].r)) + 1;
}

int getWidth(int root){
    int ans = 1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int len = q.size();
        ans = max(ans, len);
        for(int i = 0; i < len; i++){
            int t = q.front(); q.pop();
            if(node[t].l != -1) q.push(node[t].l);
            if(node[t].r != -1) q.push(node[t].r);
        }
    }
    return ans;
}
int ans = 0;
void getdis(int aim, int now, int dis){
    if(now == -1) return;
    if(aim == now) {ans = dis; return;}
    getdis(aim, node[now].l, dis+1);
    getdis(aim, node[now].r, dis+1);
}

int lca(int now, int a, int b){
    if(now == -1 || now == a || now == b) return now;
    int l = lca(node[now].l, a,b);
    int r = lca(node[now].r, a,b);
    if(l == -1) return r;
    if(r == -1) return l;
    return now;
}

int n, u, v;
int main(){
    cin >> n;
    while(--n){
        cin >> u >> v;
        if(node[u].l == -1) node[u].l = v;
        else node[u].r = v;
    }
    cin >> u >> v;
    cout << getDepth(1) << endl;
    cout << getWidth(1) << endl;
    int t = lca(1, u,v);
    getdis(u, t, 0);
    int cnt = ans*2;
    getdis(v, t, 0);
    cnt += ans;
    cout << cnt << endl;
    return 0;
}