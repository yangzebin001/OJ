#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int M[35][35];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int n;
void dfs(int i,int j){
    M[i][j] = 3;
    for(int k = 0; k < 4; k++){
        int nx = dx[k]+i;
        int ny = dy[k]+j;
        if(nx < 0 || ny < 0 || nx == n || ny == n)continue;
        if(M[nx][ny] == 0) dfs(nx,ny);
    }
}
int main(){
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool isEdge = i == 0 || i == n-1 || j == 0 || j == n-1;
            if(isEdge && M[i][j] == 0){
                dfs(i,j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != 0) printf(" ");
            if(M[i][j] == 3){
                M[i][j] = 0;
            }else if(M[i][j] == 0){
                M[i][j] = 2;
            }
            printf("%d",M[i][j]);
        }
        printf("\n");
    }
    return 0;
}