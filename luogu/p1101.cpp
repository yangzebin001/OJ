/*
 * @Date: 2020-01-25 18:36:30
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 19:01:42
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char M[110][110],res[110][110];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int rx[10],ry[10];
int n;
char toc(int x){
    if(x == 0) return 'y';
    if(x == 1) return 'i';
    if(x == 2) return 'z';
    if(x == 3) return 'h';
    if(x == 4) return 'o';
    if(x == 5) return 'n';
    if(x == 6) return 'g';
}
int ton(char c){
    if(c == 'y') return 0;
    if(c == 'i') return 1;
    if(c == 'z') return 2;
    if(c == 'h') return 3;
    if(c == 'o') return 4;
    if(c == 'n') return 5;
    if(c == 'g') return 6;
}
void dfs(int x,int y, int dir, int t){
    rx[t] = x;
    ry[t] = y;
    if(t == 6){
        for(int i = 0; i < 7; i++){
            res[rx[i]][ry[i]] = toc(i);
        }
        return;
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(toc(t+1) == M[nx][ny]) dfs(nx, ny, dir,t+1);
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",M[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = '*';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(M[i][j] == 'y'){
                for(int d = 0; d < 8; d++){
                    dfs(i,j,d,0);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s\n",res[i]);
    }
    return 0;
}