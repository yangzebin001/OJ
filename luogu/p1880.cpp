/*
 * @Date: 2020-02-12 17:04:57
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 17:25:09
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
int sum[2*MAXN],arr[2*MAXN],f1[2*MAXN][2*MAXN],f2[2*MAXN][2*MAXN];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    //变环为链
    for(int i = 1; i <= 2*n; i++){
        sum[i] = sum[i-1]+arr[i];
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l+len-1 <= 2*n; l++){
            int r = l+len-1;
            //求最小值，从无穷开始
            f2[l][r] = INF;
            for(int k = l; k < r; k++){
                f1[l][r] = max(f1[l][r],f1[l][k]+f1[k+1][r]+sum[r]-sum[l-1]);
                f2[l][r] = min(f2[l][r],f2[l][k]+f2[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    int ans1 = 0, ans2 = INF;
    for(int i = 1; i <= n; i++){
        ans1 = max(ans1,f1[i][i+n-1]);
        ans2 = min(ans2,f2[i][i+n-1]);
    }
    cout << ans2 << endl;
    cout << ans1 << endl;
    return 0;
}