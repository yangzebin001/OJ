/*
 * @Date: 2019-11-06 17:15:24
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-18 22:13:26
 */
#include<iostream>
#include<deque>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 90;
int N,M;
LL ans = 0;
deque<int> que[MAXN];
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++){
        int a;
        for(int j = 0; j < M; j++){
            scanf("%d",&a);
            // printf("%d ",a);
            que[i].push_back(a);
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(que[j].front() < que[j].back()){
                ans += (que[j].front()*(1<<i));
                que[j].pop_front();
            }else{
                ans += (que[j].back()*(1<<i));
                que[j].pop_back();
            }
        }
    }
    printf("%lld",ans);
    return 0;
}