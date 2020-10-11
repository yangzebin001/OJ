/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 11:03:54 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 11:17:49
 */

#include<iostream>
#include<algorithm>

using namespace std;
int cnt[1010];
int fs[1010][1010];
int dp[1010];
int w[1010];
int v[1010];
int n,m;
int main(){
    cin >> n >> m;
    int kk = 0;
    for(int i = 0; i < m; i++){
        int c;
        cin >> v[i] >> w[i] >> c;
        fs[c][cnt[c]] = i;
        cnt[c]++;
        kk = max(kk,c);
    }
    for(int k = 1; k <= kk; k++){  //循环每一组
        for(int i = n; i >= 0; i--){
            for(int j = 0; j < cnt[k]; j++){ //与上面一层循环不能调换位置，不然就成了 n个01背包了。
                if(i >= v[fs[k][j]])
                    dp[i] = max(dp[i], dp[i-v[fs[k][j]]] + w[fs[k][j]]);
            }
        }
    }
    cout << dp[n];
    return 0;
}