/*
 * @Date: 2019-09-04 17:29:23
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-07 10:53:37
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 100010;
int a[MAXN],R[MAXN],L[MAXN],ll,rr;
long long sum[MAXN],ans = -1;
int N;
stack<int> s;
int main(){

    //思路：将枚举区间转化为以每个点为最低点，求向左和向右最多可以延长的长度。再转化一下就是求每个数左边或者右边第一个比它小的元素后 再往回退一格（L+1,R-1)。然后求区间内的最大值。
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    a[0] = -1;
    a[N+1] = -1;
    for(int i = 1; i <= N; i++) scanf("%d",&a[i]),sum[i] = sum[i-1] + a[i];
    //求每个元素的左边第一个比它小的元素，加一 ----> 找大于等于该数的最前一个数的位置。

    //从右到左  单调递增栈
    for(int i = N; i >= 0; i--){
        while(s.size() && a[i] < a[s.top()]) {
            L[s.top()] = i+1;
            s.pop();
        }
        s.push(i);
    }
    s.pop();

    
    //求每个元素的右边第一个比它小的元素 减一 ----> 大于等于该数的最后一个数的位置
    //从左到右，单调递增栈
    for(int i = 1; i <= N+1; i++){
        while(s.size() && a[i] < a[s.top()]){
            R[s.top()] = i-1;
            s.pop();
        }
        s.push(i);
    }


    for(int i = 1; i <= N; i++){
        if((sum[R[i]] - sum[L[i]-1])*a[i] > ans){
            ans = (sum[R[i]] - sum[L[i]-1])*a[i];
            ll = L[i];
            rr = R[i];
        }
    }
    printf("%lld\n%d %d\n",ans,ll,rr);

    return 0;
}