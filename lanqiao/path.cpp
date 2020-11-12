#include<bits/stdc++.h>

using namespace std;
const int MAXN = 25;
int north[MAXN], west[MAXN];
int N;

int vis[MAXN][MAXN];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int f = 0;
int d = 0;
bool check(){
    for(int i = 0; i < N; i++){
        if(north[i]) return false;
        if(west[i]) return false;
    }
    return true;
}

void print(int x, int y, int idx){
    if(d) cout << " ";
    if(d == 0) d = 1;
    cout << x*N+y;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && vis[nx][ny] == idx+1){
            print(nx,ny,idx+1);
        }
    }
}

void dfs(int x, int y, int idx){
    if(f) return;
    if(vis[x][y] || !north[y] || !west[x]) return;
    vis[x][y] = idx;
    west[x]--;
    north[y]--;

    if(x == N-1 && y == N-1 && check()){
        print(0,0,1);
        f = 1;
        return;
        
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N ){
            dfs(nx,ny,idx+1);
        }
    }

    vis[x][y] = 0;
    west[x]++;
    north[y]++;

}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> north[i];
    }
    for(int i = 0; i < N; i++){
        cin >> west[i];
    }

    dfs(0,0,1);
    return 0;   
}