/*
 * @Date: 2019-10-26 23:06:57
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-27 10:10:08
 */
#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+10;
typedef double DD;
typedef pair<DD,DD> PDD;
PDD arr[MAXN];
int N;
//按破坏力/时间排序
// 假设有两头牛分别编号1,2，1号牛牵走需要花费x1秒，吃花的速率是y1，
// 2号牛牵走需要x2秒，吃花的速率是y2，假设先牵走1号牛，那么2号牛将要吃y2*x1数量的花，
// 如果先牵走2号牛，那么1号牛要吃y1*x2数量的花，假设二号牛吃得花比1号牛多，
// 那么就有关系式y2*x1>y1*x2，那么可以移项得到y2/x2>x2/x1，
// 所以这样就可以按照这个速率比时间的值来贪心，让被牛吃的花尽量少。

bool cmp(PDD a, PDD b){
    return a.first / a.second > b.first / b.second;
}
int main(){
    freopen("in.txt","r",stdin);
    DD sum = 0,time = 0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++) scanf("%lf%lf",&arr[i].second,&arr[i].first),sum += arr[i].first;
    DD ans = 0;
    sort(arr,arr+N,cmp);
    //最后一个不算结果。
    for(int i = 0; i < N-1; i++){
        // 带走一个花需要2*time_i时间。
        // 先带走一个，再算剩下的，乘以时间。
        sum -= arr[i].first;
        ans += 2*sum*arr[i].second;
        cout << sum << " " << ans << endl;
    }
    
    
    printf("%.0lf",ans);
    return 0;
}