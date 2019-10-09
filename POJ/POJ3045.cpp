/*
 * @Date: 2019-09-27 23:11:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-28 16:39:27
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 5e4+10;
// long long sum[MAXN];
struct node{
    int w,s;
}a[MAXN];
bool cmp(node a, node b){
    return a.s+a.w > b.s+b.w;
}
int N;


/*
1：对于每头牛而言，视他与他上面的牛为一个整体，总重为sum_w，那么对于这头牛的危险值为sum_w-w-s，
要想sum_w-(w+s)的值最小，w+s的值就应该最大，由此可见取最优化，wi+si越大越应该在下面。


2：假设目前排放的的序列是最优排列。任意位置有第一头牛和第二头牛分别有w1，s1；w2，s2。
第一头牛上面的牛的重量总和为sum。且第一头牛在第二头牛上面，
可以知道危险指数分别为a=sum-s1，b=sum+w1-s2。
现在调换两头牛的位置，可得a'=sum+w2-s1，b'=sum-s2。  
因为之前是最优排列，所以得知w2-s1>=w1-s2, 
移项可得：
w2+s2>=w1+s1，所以体重和力量之和越大越在底下。
*/
int main(){
    scanf("%d",&N);
    long long sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%d%d",&a[i].w,&a[i].s);
        sum += a[i].w;
    }
    sort(a,a+N,cmp);
    long long ans = -0x3f3f3f;
    for(int i = 0; i < N; i++){
        sum -= a[i].w;
        //背负的重量减去自身的力量。
        ans = max(ans,sum-a[i].s);
    }
    
    printf("%lld\n",ans);
    return 0;
}