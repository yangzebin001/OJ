/*
 * @Date: 2020-04-11 16:23:37
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-04-12 08:11:33
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN = 2010;
struct Stu{
  int team;
  int lscore;
  int totalScore;
}stu[MAXN];
int teamScore[26][26];
double ts1[26];
int ts2[26];
int n,k;

double getAvg1(int a[]){
  double sum = 0;
  for(int i = 0; i < k; i++){
    sum += a[i];
  }
  return sum/k;
}
int getAvg2(int a[],int j){
  double sum = 0;
  int cnt = 0;
  for(int i = 0; i < k; i++){
    if(fabs(ts1[j]-a[i]) <= 15.0){
      sum += a[i];
      cnt++;
    }
  }
  // printf("%d ",cnt);
  return round(sum/cnt);
  
}

int cmp(Stu a, Stu b){
  if(a.totalScore == b.totalScore){
    return a.team < b.team;
  }
  return a.totalScore > b.totalScore;
}
int main(){
  scanf("%d%d",&n,&k);
  char t[2];
  for(int i = 0; i < n; i++){
    scanf("%d%s",&stu[i].lscore,t);
    stu[i].team = t[0]-'A';
  }
  for(int i = 0; i < k; i++){
    for(int j = 0; j < k; j++){
      int a;
      scanf("%d",&a);
      teamScore[j][i] = a;
    }
  }

  for(int i = 0; i < k; i++){
    ts1[i] = getAvg1(teamScore[i]);
    ts2[i] = getAvg2(teamScore[i], i);
  }
  for(int i = 0; i < n; i++){
    int tt = stu[i].team;
    stu[i].totalScore = round(stu[i].lscore * 0.6 + ts2[tt] * 0.4);
  }
  sort(stu,stu+n,cmp);
  for(int i = 0; i < n; i++){
    printf("%d %c\n",stu[i].totalScore,'A'+stu[i].team);
  }
  return 0;
}