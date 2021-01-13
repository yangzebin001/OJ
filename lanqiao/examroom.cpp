#include<bits/stdc++.h>

using namespace std;
int n,m;
const int MAXN = 110;
int rel[MAXN][MAXN];

vector<vector<int>> rooms;
int ans = INT_MAX;
bool check(int idx, int c){
    for(int i = 0; i < rooms[idx].size(); i++){
        if(rel[rooms[idx][i]][c]) return false;
    }
    return true;

}

void dfs(int idx){
    if(idx == n+1){
        ans = min(ans,(int)rooms.size());
        return;
    }
    if(rooms.size() > ans) return;
    for(int i = 0; i < rooms.size(); i++){
        if(check(i,idx)){
            rooms[i].push_back(idx);
            dfs(idx+1);
            rooms[i].pop_back();
        }
    }
    vector<int> c;
    c.push_back(idx);
    rooms.push_back(c);
    dfs(idx+1);
    rooms.pop_back();
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        rel[a][b] = 1;
        rel[b][a] = 1;
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}