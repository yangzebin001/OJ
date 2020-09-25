#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

char field[110][110];
int n,m, ans;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void dfs(int x, int y){
    
    for(int i = 0; i < 8; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 'W'){
            field[nx][ny] = '.';
            dfs(nx,ny);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%s", field[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j] == 'W'){
                // for(int k = 0; k < n; k++){
                //     printf("%s\n", field[k]);
                // }
                // printf("\n");
                field[i][j] = '.';
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}