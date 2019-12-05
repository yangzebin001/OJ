/*
 * @Date: 2019-09-05 21:32:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-05 23:15:36
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long LL;

const int MAXN = 1000010;

LL arr[MAXN],s[MAXN],sum[MAXN],N,ans = -1;
stack<LL> stk;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%lld",&N);
    arr[0] = 2000000100;
    arr[N+1] = 2000000100;
    for(int i = 1; i <= N; i++){
        scanf("%lld%lld",&arr[i],&s[i]);
    }
    //找一个数左右两边离该数最近的并且比该数大的数的位置
    
    //单调递减栈。 找当前数的右边目标数
    for(int i = 1; i <= N+1; i++){
        //找到了比当前栈顶大的数，更新值
        while(stk.size() && arr[i] > arr[stk.top()]){
            //大发射站可以吸收小发射站的能量。
            sum[i] += s[stk.top()];
            stk.pop();
        }
        stk.push(i);
    }
    stk.pop();
    

    //单调递减栈。 找当前数的左边目标数
    for(int i = N; i >= 0; i--){
        //找到了比当前栈顶大的数，更新值
        while(stk.size() && arr[i] > arr[stk.top()]){
            //大发射站可以吸收小发射站的能量。
            sum[i] += s[stk.top()];
            stk.pop();
        }
        stk.push(i);
    }
    stk.pop();
    for(int i = 1; i <= N; i++) ans = max(ans,sum[i]);
    printf("%lld",ans);
    return 0;
}