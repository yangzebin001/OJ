/*
 * @Date: 2019-10-12 14:43:56
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-15 16:40:14
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 200;
struct n{
    vector<int> sub;
}node[MAXN];
vector<int> ans;
int N,M,K;

void bfs(){
    queue<int> q;
    q.push(1);
    while(q.size()){
        int s = q.size();
        int cnt = 0;
        for(int i = 0; i < s; i++){
            int a = q.front(); q.pop();
            if(node[a].sub.empty()) cnt++;
            for(int i = 0; i < node[a].sub.size(); i++){
                q.push(node[a].sub[i]); 
            }
        }
        ans.push_back(cnt);
    }
    
}
int main(){
    freopen("in.txt","r",stdin);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int r;
        cin >> r >> K;
        for(int j = 0; j < K; j++){
            int l;
            cin >> l;
            node[r].sub.push_back(l);
        }
    }
    bfs();
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " ";
        printf("%d",ans[i]);
    }
    return 0;
}