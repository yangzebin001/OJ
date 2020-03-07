/*
 * @Date: 2020-03-07 14:47:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 17:27:55
 */
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> PII;
char M[1010][1010];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int main(){
  int n,m;
  int x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for(int i = 0; i < n; i++){
    scanf("%s",M[i]);
  }
  int cnt = 0;
  queue<PII> q;
  q.push(make_pair(x,y));
  M[x][y] = '0';
  while(q.size()){
    int x = q.front().first, y = q.front().second;
    q.pop();
    cnt++;
    for(int i = 0; i < 4; i++){
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && M[nx][ny] == '1'){
        q.push(make_pair(nx,ny));
        M[nx][ny] = '0';
      }
    }
  }
  cout << cnt << endl;
  return 0;
}