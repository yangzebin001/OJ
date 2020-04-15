/*
 * @Date: 2020-03-14 14:34:26
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-14 14:45:23
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;

struct node{
  int x,y,s;
  node(){};
  node(int _x, int _y, int _s):x(_x),y(_y),s(_s){};
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char M[1010][1010];
int vis[1010][1010];

int main(){
  queue<node> q;
  int n,m,t;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    scanf("%s",M[i]);
    for(int j = 0; j < m; j++){
      if(M[i][j] == 'g'){
        q.push(node(i,j,0));
        vis[i][j] = 1;
      }
    }
  }
  cin >> t;
  while(!q.empty()){
    int x = q.front().x, y = q.front().y, s = q.front().s;
    q.pop();

    if(s == t) continue;
    for(int i = 0; i < 4; i++){
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
        vis[nx][ny] = 1;
        M[nx][ny] = 'g';
        q.push(node(nx,ny,s+1));
      }
    }
  }
  for(int i = 0; i < n; i++){
    printf("%s\n",M[i]);
  }
  return 0;
}