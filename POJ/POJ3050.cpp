/*
 * @Date: 2019-10-05 22:25:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-05 22:40:53
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int M[10][10];
set<int> s;
void dfs(int x,int y,int cnt,int data){
    if(cnt == 6){
        // if(!s.count(data)) printf("%d\n",data);
        s.insert(data);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            dfs(nx,ny,cnt+1,data*10+M[x][y]);
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&M[i][j]);
        }
    }
    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(i,j,0,0);
        }
    }
    printf("%d\n",s.size());
    return 0;
}