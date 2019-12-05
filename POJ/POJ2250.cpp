/*
 * @Date: 2019-11-16 11:01:40
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-16 11:53:02
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 110;
int dp[MAXN][MAXN];
int vis[MAXN][MAXN];
string A[MAXN],B[MAXN];
int t1,t2;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset(vis,-1,sizeof(vis));
    string a;
    int q = 2;
    while(cin >> a && a != "#"){
        A[t1++] = a;
    }
    while(cin >> a && a != "#"){
        B[t2++] = a;
    }

    for(int i = 0; i < t1; i++){
        for(int j = 0; j < t2; j++){
            if(A[i] == B[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                vis[i+1][j+1] = q++;
            }else{
                if(dp[i+1][j]>=dp[i][j+1]){
                    dp[i+1][j+1] = dp[i+1][j];
                }else{
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
    }
    for(int i = 1; i <= t1; i++){
        for(int j = 1; j <= t2; j++){
            printf("%7d",vis[i][j]);
        }
        printf("\n");
    }
    return 0;
}