/*
 * @Date: 2019-11-07 16:07:59
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-07 16:21:09
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 1e5+10;
vector<int> M[MAXN];
int vis[MAXN];
int level(int c){
    int t = c;
    queue<int> q;
    for(int i = 0; i < M[c].size(); i++){
        q.push(M[c][i]);
    }
    while(q.size()){
        t = q.front();
        q.pop();
        for(int i = 0; i < M[t].size(); i++){
            q.push(M[t][i]);
        }
    }
    return t;
}
int N;
int main(){
    memset(vis,-1,sizeof(vis));
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        int k;
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            int a;
            scanf("%d",&a);
            vis[a] = i;
            M[i].push_back(a);
        }
    }
    int c = -1;
    for(int i = 1; i <= N; i++){
        if(vis[i] == -1) c = i;
    }
    printf("%d",level(c));
    return 0;
}