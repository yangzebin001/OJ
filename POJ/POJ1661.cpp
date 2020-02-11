/*
 * @Date: 2020-01-31 15:58:11
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-01 17:00:39
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+10;
const int INF = 0x3f3f3f3f;
int N,X,Y,MAXH;
struct floor{
    int x,y,h;
}Floor[MAXN];
int dp[MAXN][2];
int cmp(const floor a, const floor b){
    return a.h < b.h;
}
void solve(){
    
    for(int i = 0; i < N; i++){
        cin >> Floor[i].x >> Floor[i].y >> Floor[i].h;
    }
    Floor[N].x = X, Floor[N].y = X, Floor[N].h = Y; //起始位置

    //从地面开始，反向跳到起始地
    sort(Floor,Floor+N+1,cmp);
    memset(dp,INF,sizeof dp);
    for(int j = 0; j <= N; j++){
        int lp = -1, rp = -1;
        for(int k = j-1; k >= 0; k--){
            //寻找比当前板子低的并且能包含住左端点的第一个板子
            if(lp == -1 && Floor[k].x <= Floor[j].x && Floor[k].y >= Floor[j].x){
                lp = k;
            }
            //寻找比当前板子低的并且能包含住右端点的第一个板子
            if(rp == -1 && Floor[k].x <= Floor[j].y && Floor[k].y >= Floor[j].y){
                rp = k;
            }
        }
        //没有板子在该板子下面了（地面）
        if(lp == -1 && Floor[j].h <= MAXH)
            dp[j][0] = Floor[j].h;
        if(rp == -1 && Floor[j].h <= MAXH)
            dp[j][1] = Floor[j].h;

        //有板子，要更新端点的值
        int dish1 = Floor[j].h-Floor[lp].h;
        if(lp != -1 && dish1 <= MAXH){
            dp[j][0] = min(dp[lp][0]+Floor[j].x-Floor[lp].x,dp[lp][1]+Floor[lp].y-Floor[j].x) + dish1;
        }
        int dish2 = Floor[j].h-Floor[rp].h;
        if(rp != -1 && dish2 <= MAXH){
            dp[j][1] = min(dp[rp][0]+Floor[j].y-Floor[rp].x,dp[rp][1]+Floor[rp].y-Floor[j].y) + dish2;
        }
    }
    printf("%d\n",dp[N][0]);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> N >> X >> Y >> MAXH;
        solve();
    }
    return 0;
}