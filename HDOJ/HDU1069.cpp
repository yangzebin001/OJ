/*
 * @Date: 2020-01-25 13:03:04
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 13:56:36
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 30*6;
int dp[MAXN];
struct block{
    int l,w,h;
}B[MAXN];
int cmp(block &a, block &b){
    if(a.l == b.l) return a.w > b.w;
    return a.l > b.l;
}
int main(){
    int n,t;
    int T = 0;
    while(scanf("%d",&n),n){
        t = 0;
        int l,w,h;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d",&l,&w,&h);
            if(l>w){
                B[t].l = l; B[t].w = w; B[t++].h = h;
            }else{
                B[t].l = w; B[t].w = l; B[t++].h = h;
            }

            if(l > h){
                B[t].l = l; B[t].w = h; B[t++].h = w;
            }else{
                B[t].l = h; B[t].w = l; B[t++].h = w;
            }

            if(w > h){
                B[t].l = w; B[t].w = h; B[t++].h = l;
            }else{
                B[t].l = h; B[t].w = w; B[t++].h = l;
            }
            
        }
        sort(B,B+t,cmp);
        // dp[0] = B[0].h;
        for(int i = 0; i < t; i++){
            dp[i] = B[i].h;
            int lasth = 0;
            for(int j = 0; j < i; j++){
                if(B[j].l > B[i].l && B[j].w > B[i].w){
                    lasth = max(lasth,dp[j]);
                }
            }
            dp[i] += lasth;
        }
        printf("Case %d: maximum height = %d\n",++T,*max_element(dp,dp+t));

    }
    return 0;
}