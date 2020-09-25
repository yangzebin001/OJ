#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n,r;

vector<int> now;

void dfs(vector<int> &now, int idx){
    if(now.size() == r){
        for(int i = 0; i < now.size(); i++){
            printf("%3d", now[i]);
        }
        printf("\n");
        return;
    }
    if(idx > n) return;
    now.push_back(idx);
    dfs(now, idx+1);
    now.pop_back();
    dfs(now, idx+1);
}

int main(){
    cin >> n >> r;
    dfs(now, 1);
    return 0;
}