/*
 * @Date: 2020-03-07 13:41:00
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-07 13:46:58
 */
#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
  int id,H,D;
}Stu[1000010];
int cmp(struct stu a, struct stu b){
  if(a.H == b.H){
    if(a.D == b.D){
      return a.id < b.id;
    }
    return a.D < b.D;
  }
  return a.H < b.H;
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d%d",&Stu[i].H,&Stu[i].D);
    Stu[i].id = i;
  }
  sort(Stu,Stu+n,cmp);
  for(int i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d",Stu[i].id+1);
  }
  return 0;
}