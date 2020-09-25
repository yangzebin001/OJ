#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

vector<int> edge[26];
string s;
int n, start = 1;
int ind[26], outd[26], vis[1010];
string ss[1010];
int ans[1010];

void dfs(int pos, int cnt){
    ans[cnt] = pos;
    if(cnt == n){
        for(int i = 1; i < n; i++){
            cout << ss[ans[i]] << ".";
        }
        cout << ss[ans[n]];
        exit(0);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i] && ss[pos].back() == ss[i][0]){
            vis[i] = 1;
            dfs(i, cnt+1);
            vis[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ss[i];
        ind[ss[i][0]-'a']++;
        outd[ss[i].back()-'a']++;
    }
    sort(ss+1, ss+n+1);
    //寻找起点 欧拉通路：有一个顶点入度比出度大1，有一个顶点出度比入度大1
    for(int i = 1; i <= n; i++){
        if(ind[ss[i][0]-'a'] - outd[ss[i][0]-'a'] == 1){
            start = i;
            break;
        }
    }
    vis[start] = 1;
    dfs(start, 1);

    printf("***");
    return 0;
}