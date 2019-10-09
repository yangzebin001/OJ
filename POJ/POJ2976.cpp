/*
 * @Date: 2019-09-28 16:40:15
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-29 18:14:27
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1000+10;
int n,k;
struct node{
    int a,b;
}num[MAXN];

double f[MAXN];

/*
题意：有N个考试，每个考试有ai和bi两个值，最后成绩由上面的公式求得。幸运的是，可以放弃K个科目，求最大化最后的成绩。
思路：由题意可知当，当n-k个科目组成最优解时，再增加别的科目，解一定不如原来的解，放弃掉k个科目是最好的方案。
于是，题目就变成了最小化平均值的问题，另外在注意下取整时的四舍五入就好了。
最小化平均值: 有n个物品的重量和价值分别为wi和vi，从中选择k个物品使得单位重量的价值最大。
对于这个问题，我们可以用二分搜索解决，先来看看判断条件：
设最大值为先，则需要满足 ∑vi / ∑wi >=x，把不等式进行变形，就得到了 ∑ ( vi - x * wi )>=0，于是判断就成了，对 vi-x*wi 的值进行排序之后贪心进行选择，判断前k个的和是否不小于0。判断的复杂度是O（nlogn）。
*/
bool check(double x){
    for(int i = 0; i < n; i++) f[i] = num[i].a - x*num[i].b;
    sort(f,f+n);
    double sum = 0;
    for(int i = 0; i <n-k; i++) sum += f[n-1-i];
    return sum >= 0;
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!= EOF && n+k){
        for(int i = 0; i < n; i++){
            scanf("%d",&num[i].a);
        }
        for(int i = 0; i < n; i++){
            scanf("%d",&num[i].b);
        }
        double l = 0, r = 1e9;
        for(int i = 0; i < 100; i++){
            double mid = (l+r)/2;
            if(check(mid)) l = mid;
            else r = mid;
        }
 
		printf("%d\n", int(l*100+0.5));

        // int ans = 100 * (l+0.005);
		// printf("%d\\n", ans);
    }

}