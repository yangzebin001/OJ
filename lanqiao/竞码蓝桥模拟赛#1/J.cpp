/*
 * @Date: 2020-02-07 16:30:58
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 11:47:15
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e7+10;
int cnt[MAXN];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 2; i <= n; i++){
        for(int j = 1; j*i <= n; j++){
            cnt[j*i]++;
        }
    }
    sort(cnt+2,cnt+n+1);
    // for(int i = 2; i <= n; i++){
    //     cout << cnt[i] << " ";
    // }
    cout << cnt[k+1]+1;
    return 0;
}