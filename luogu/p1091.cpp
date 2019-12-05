/*
 * @Date: 2019-11-13 18:18:08
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-13 20:08:28
 */
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){return a>b;}
const int MAXN = 110;
int N;
int arr[MAXN],dp1[MAXN],dp2[MAXN];
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    int res = MAXN;
    for(int i = 0; i < N; i++) scanf("%d",&arr[i]);
    for(int i = 0; i < N; i++){
        //以每个顶点为中心，分别求两侧的最长递减子序列的长度：len = len1+1。
        //取其中N-len最小的。
        int len1 = 0,len2 = 0;
        dp1[len1] = arr[i];
        for(int j = i+1; j < N; j++){
            if(dp1[len1] > arr[j]) dp1[++len1] = arr[j];
            else{
                //因为是严格单调递减的，所以相等情况也要替换。
                int p = lower_bound(dp1,dp1+len1,arr[j],cmp) - dp1;
                dp1[p] = arr[j];
            }
        }
        for(int k = 0; k <= len1; k++) printf("%d ",dp1[k]);
        printf("\n");
        dp2[len2] = arr[i];
        for(int j = i-1; j >= 0; j--){
            if(dp2[len2] > arr[j]) dp2[++len2] = arr[j];
            else{
                int p = lower_bound(dp2,dp2+len2,arr[j],cmp) - dp2;
                dp2[p] = arr[j];
            }
        }
        res = min(res,N-(len1+1+len2+1-1));//中间位置被计算了两次，减1.
    }
    printf("%d",res);
    return 0;
}