#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int m[10][10];
int row[9][19];
int col[9][19];
int cell[3][3][19];

bool isvaild(int x,int y, int n){
    for(int i = 0; i < 9; i++){
        if(m[i][y] == n || m[x][i] == n) return false;
    }
    for(int i = x/3*3; i < x/3*3+3; i++){
        for(int j = y/3*3; j < y/3*3+3; j++){
            if(m[i][j] == n) return false;
        }
    }
    return true;
}
int f = 0;
void dfs(int x,int y){
    // printf("%d %d",x,y);
    if(f) return;
    if(x == 9){
        x = 0; y++;
    }
    if(y == 9){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                printf("%d",m[i][j]);
            }
            printf("\n");
        }
        f = 1;
        return;
    }
    if(m[x][y] != 0) dfs(x+1,y);
    else{
        for(int i = 9; i >= 0; i--){
            if(!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]){
                m[x][y] = i;
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = 1;
                dfs(x+1,y);
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = 0;
                m[x][y] = 0;
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        f = 0;
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        memset(cell,0,sizeof(cell));
        for(int i = 0; i < 9; i++){
            char c[13];
            scanf("%s",c);
            for(int j = 0; j < 9; j++){
                int a = c[j]-'0';
                m[i][j] = a;
                col[j][a] = 1;
                row[i][a] = 1;
                cell[i/3][j/3][a] = 1;
            }
        }
        dfs(0,0);
    }
    return 0;
}