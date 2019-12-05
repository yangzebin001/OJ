/*
 * @Date: 2019-10-19 16:52:09
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-19 18:05:51
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef pair<int,int> PII;
const int MAXN = 50000+10;
PII arr[MAXN];
int N,M;
int ans = 1;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0; i < N; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        arr[i].first = l;
        arr[i].second = r;
        if(l == 1) cnt1 = 1;
        if(r == M) cnt2 = 1;
    }
    if(cnt1 != 1 || cnt2 != 1){
        printf("-1\n");
        return 0;
    }
    sort(arr,arr+N);
    int ans = 0, maxr = 0;
    for(int i = 0; i < N; ){
        int j = i;
        int tm = maxr;
        //区间内选最远
        while(j < N && arr[j].first <= maxr+1){
            tm = max(tm,arr[j].second);
            j++;
        }
        //找到了
        if(tm >= M){
            printf("%d\n",++ans);
            return 0;
        }
        //如果区间内就没有更新，说明没有能够接上，直接返回
        if(tm == maxr){
            printf("-1\n");
            return 0;
        }
        //更新区间。
        ans++;
        maxr = tm;
        i = j;
    }
    return 0;
}