/*
 * @Date: 2020-04-19 14:32:24
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-19 14:43:16
 */
#include<iostream>
#include<algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int M[1010][1010];
int main(){
  int n,m,r,c;
  cin >> n >> m >> r >> c;
  int i = 1, j = 0;
  int t = 0;
  int now = 1;
  while(1){
    int di = i + dx[t];
    int dj = j + dy[t];
    if(di < 1 || di > n || dj < 1 || dj > m || M[di][dj]){
      t = (t +1)%4;
      di = i + dx[t];
      dj = j + dy[t];
    }
    i = di;
    j = dj;
    // cout << i << " " <<j << endl;
    M[i][j] = now++;
    if(now == n * m + 1) break;
  }
  cout << M[r][c] << endl;
  return 0;
}