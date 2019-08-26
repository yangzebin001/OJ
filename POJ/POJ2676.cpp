#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int m[10][10];

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
            if(isvaild(x,y,i)){
                m[x][y] = i;
                dfs(x+1,y);
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
        for(int i = 0; i < 9; i++){
            char c[13];
            scanf("%s",c);
            for(int j = 0; j < 9; j++){
                m[i][j] = c[j]-'0';
            }
        }
        dfs(0,0);
    }
    return 0;
}