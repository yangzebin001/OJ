/*
 * @Date: 2020-02-22 14:10:07
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-02-22 14:42:06
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
  int l = -1,m = -1,r = -1,num;
}Node[12];
// a b c d e f g h i j k l
// 0 1 2 3 4 5 6 7 8 9 10 11
int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

int dfs(int root){
  if(Node[root].l == -1 && Node[root].m == -1 && Node[root].r == -1){
    return Node[root].num;
  }
  int cnt = 0;
  int lsum = 0, msum = 0, rsum = 0;
  if(Node[root].l != -1){
    lsum = dfs(Node[root].l);
    
  }
  if(Node[root].m != -1){
    msum = dfs(Node[root].m);
  }
  if(Node[root].r != -1){
    rsum = dfs(Node[root].r);
  }
  if(lsum == -1 || msum == -1 || rsum == -1) return -1;
  cnt += lsum + msum + rsum + Node[root].num;
  if(cnt % 2) return -1;
  return cnt;
}

int main(){
  // int cnt = 0;
  // Node[0].l = 1; Node[0].m = 2; Node[0].r = 3; 
  // Node[1].l = 4;
  // Node[2].l = 5; Node[2].r = 6;
  // Node[3].l = 7; Node[3].r = 8;
  // Node[6].l = 9; Node[6].r = 10;
  // Node[8].r = 11;
  // do{
  //   for(int i = 0; i <12; i++){
  //     Node[i].num = arr[i];
  //   }
  //   if(dfs(0) != -1){
  //     for(int j = 0; j < 12; j++){
  //       cout << arr[j] << " ";
  //     }
  //     cout << endl;
  //     cnt++;
  //   }
  // }while(next_permutation(arr,arr+12));
  // cout << cnt << endl;
  // 8294400
  // 11404800
  //1 2 3 5 4 8 10 6 7 9 11 12
  // Node[0].num = 1;
  // Node[1].num = 2;
  // Node[2].num = 3;
  // Node[3].num = 5;
  // Node[4].num = 4;
  // Node[5].num = 8;
  // Node[6].num = 10;
  // Node[7].num = 6;
  // Node[8].num = 7;
  // Node[9].num = 9;
  // Node[10].num = 11;
  // Node[11].num = 12;
  // printf("%d",dfs(8));
  cout << 11404800 << endl;
  return 0;
}