#include<bits/stdc++.h>

using namespace std;
int n;
char field[1010][1010];
char ans[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int vis[1010][1010];
bool dfs(int x, int y){
    vis[x][y] = 1;
    bool t = false;
    if(ans[x][y] == '#') t = true;
    for(int k = 0; k < 4; k++){
        int nx = dx[k] + x;
        int ny = dy[k] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == '#' && !vis[nx][ny]){
            t |= dfs(nx,ny);
        }
    }
    return t;
}

void dfs2(int x, int y){
    vis[x][y] = 1;
    for(int k = 0; k < 4; k++){
        int nx = dx[k] + x;
        int ny = dy[k] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == '#' && !vis[nx][ny]){
            dfs2(nx,ny);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s",field[i]);
    }
    memcpy(ans,field, sizeof(field));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(field[i][j] == '#'){
                for(int k = 0; k < 4; k++){
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == '.'){
                        ans[i][j] = '.';
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0;  i < n; i++){
        for(int j = 0; j < n; j++){
            if(field[i][j] == '#' && !vis[i][j]) {
                dfs2(i,j);
                cnt++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i = 0;  i < n; i++){
        for(int j = 0; j < n; j++){
            if(field[i][j] == '#' && !vis[i][j]) cnt -= dfs(i,j);
        }
    }
    cout << cnt << endl;
    return 0;
}