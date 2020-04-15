/*
 * @Date: 2020-03-14 14:51:10
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-18 18:38:15
 */
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
  int idx,good;
}Node[400010];

int n,m,_n;
void init(){
  n = 1;
  while(n < _n) n *= 2;
}

void update(int k, int idx, int good){
  k += n-1;
  Node[k].idx = idx;
  Node[k].good = good;
  //从树底向上更新
  while(k > 0){
    k = (k-1)/2;
    if(Node[k*2+1].good > Node[k*2+2].good){
      Node[k].good = Node[k*2+1].good;
      Node[k].idx = Node[k*2+1].idx;
    }else{
      Node[k].good = Node[k*2+2].good;
      Node[k].idx = Node[k*2+2].idx;
    }
  }
}

pair<int,int> query(int a, int b, int k, int l, int r){
  //两区间不相交
  if(a > r || l > b) return {-1,-1};
  //完全包含
  if(a <= l && r <= b) return {Node[k].idx,Node[k].good};
  int mid = (l+r)/2;
  pair<int,int> vl = query(a,b,k*2+1,l,mid);
  pair<int,int> vr = query(a,b,k*2+2,mid+1,r);
  //选好看值大的
  if(vl.second == vr.second){
    return vl.first < vr.first ? vl : vr;
  }
  return vl.second > vr.second ? vl : vr;
}

int main(){
  scanf("%d%d",&_n,&m);
  init();
  for(int i = 0; i < _n; i++){
    int val;
    scanf("%d",&val);
    update(i,i,val);
  }
  int lpos = 0, rpos = _n-m;
  for(int i = 0; i < m; i++){
    pair<int,int> ans = query(lpos,rpos,0,0,n-1);
    cout << ans.second << " ";
    //更新左右边界
    lpos = rpos+1;
    rpos++;
  }

  return 0;
}


/*
5 3
9 10 1 2 3
10 2 3
*/