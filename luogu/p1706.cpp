#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int n;
int vis[10];
vector<int> now;

void dfs(vector<int> &now){
    if(now.size() == n){
        for(int i = 0; i < now.size(); i++){
            printf("%5d", now[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            now.push_back(i);
            dfs(now);
            now.pop_back();
            vis[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    dfs(now);
    return 0;
}