/*
 * @Date: 2020-01-19 21:46:04
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-19 22:02:03
 */
#include<iostream>
#include<map>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;
int main(){
    // freopen("in.txt","r",stdin);
    set<int> vis;
    int t;
    scanf("%d",&t);
    while(t--){
        vis.clear();
        int n,s,k;
        scanf("%d%d%d",&n,&s,&k);
        for(int i = 0; i < k; i++){
            int a;
            scanf("%d",&a);
            vis.insert(a);
        }
        int step = 1e9+10;
        for(int i = s; i <= n; i++){
            if(!vis.count(i)){
                step = min(step,i-s);
                break;
            }
        }
        for(int i = s; i >= 1; i--){
            if(!vis.count(i)){
                step = min(step,s-i);
                break;
            }
        }
        printf("%d\n",step);
    }
    return 0;
}
