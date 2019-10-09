/*
 * @Date: 2019-09-10 19:44:08
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-10 19:52:01
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 100005;
int arr[MAXN];
int ans = 0;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n; i++){
        int cal = 0;
        for(int j = i; j < n; j++){
            cal ^= arr[j];
            if(cal == 0 || cal == (1<<k)-1) ans = max(ans,j-i+1);
        }
    }
    printf("%d",ans);
    return 0;
}