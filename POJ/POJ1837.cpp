#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//第i个砝码在第j权值下的处于平衡时的方案数
int dp[21][15000]; //20*25*15*2; 权值（位置*重量） 
int v[30],w[30];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= m; i++) cin >> w[i];
    dp[0][7500] = 1; //杠杆初始平衡位置
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 15000; j++){
            //优化：只有当之前的状态处于平衡时，才转移
            if(dp[i-1][j]){
                for(int k = 1; k <= n; k++){
                    //如果在当前位置选用了当前砝码，由于要处于平衡状态，对称的相应权值位置就可以由当前的状态转移。
                    if(j>=v[k]*w[i])
                        dp[i][j-v[k]*w[i]] += dp[i-1][j];
                }
            }
        }
    }
    //选了m个砝码之后最后的平衡位置。
    cout << dp[m][7500];
    return 0;
}