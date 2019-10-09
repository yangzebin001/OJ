/*
 * @Date: 2019-10-06 17:36:17
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-07 17:18:16
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;

struct cow{
    int csat,aid;
    bool operator <(const cow &q)const{
        if(csat == q.csat) return aid < q.aid;
        return csat < q.csat;
    }
}cows[MAXN];
struct n{
    int index,aid;
    bool operator <(const n &q)const{
        return aid < q.aid;
    }
}node[MAXN];
int M,N,S,half,ans = -1;
int aid[MAXN];

int check(int x){
    int l = 0, r = 0, sum = cows[x].aid;
    for(int i = 0; i < N; i++){
        //在原位置的左边，且符合规定
        if(l < half && node[i].index < x && sum + node[i].aid <= S){
            l++;
            sum += node[i].aid;
        //在原位置的右边，且符合规定
        }else if(r < half && node[i].index > x && sum + node[i].aid <= S){
            r++;
            sum += node[i].aid;
        }
    }
    //都到不了half，说明无法满足小于等于S。
    if(l < half && r < half) return -1;
    if(l < half) return 1;
    else if(r < half) return 0;
    //l = r = half 找到了一个符合条件的，更新答案，继续寻找后面。
    ans = cows[x].csat;
    return 1;
    
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&M,&N,&S);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&cows[i].csat,&cows[i].aid);
    }
    half = M/2;
    sort(cows,cows+N);//先按分数排序
    for(int i = 0; i < N; i++){
        node[i].index = i; //记录位置关系
        node[i].aid = cows[i].aid;
    }
    sort(node,node+N); //排序是为了寻找尽可能小的aid
    int l = 0, r = N-1;
    while(l < r){
        int mid = l+r+1>>1;
        //试探中位数。
        int f = check(mid);
        if(f == 1) l = mid;
        else if(f == 0) r = mid-1;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
