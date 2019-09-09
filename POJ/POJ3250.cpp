/*
 * @Date: 2019-09-04 16:39:06
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-06 21:54:19
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
struct node{
    int a,x;
    node(){}
    node(int _a, int _x):x(_x),a(_a){}
};

stack<node> s;

int main(){
    freopen("in.txt","r",stdin);
    int n;
    long long ans = 0;
    scanf("%d",&n);
    node temp;
    for(int i = 1; i <= n; i++){
        scanf("%d",&temp.a);
        temp.x = i;
        //单调递减栈
        //对于当前栈顶，找到了第一个大于等于他的值（刚读入的值）。
        while(s.size() && s.top().a <= temp.a){
            //计算坐标差
            ans += i-s.top().x-1;
            s.pop();
        }
        s.push(temp);
    }
    //当前栈顶元素的右边没有比他更高的元素了，用最右边的无限高减去该元素位置。
    while(s.size()){
        ans += n-s.top().x;
        s.pop();
    }
    printf("%lld\n",ans);
    return 0;
}