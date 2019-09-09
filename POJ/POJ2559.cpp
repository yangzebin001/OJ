/*
 * @Date: 2019-09-07 15:54:47
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-07 16:03:29
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;

LL a[MAXN],L[MAXN],R[MAXN];
int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n){
        stack<int> s;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        for(int i = 1; i <= n; i++){
            scanf("%lld",&a[i]);
        }
        a[0] = -1;
        a[n+1] = -1;
        for(int i = 1; i <= n+1; i++){
            while(s.size() && a[i] < a[s.top()]){
                R[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
        s.pop();
        for(int i = n; i >= 0; i--){
            while(s.size() && a[i] < a[s.top()]){
                L[s.top()] = i+1;
                s.pop();
            }
            s.push(i);
        }
        s.pop();
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans,(R[i]-L[i]+1)*a[i]);
        }
        printf("%lld\n",ans);
        
    }
    return 0;
}