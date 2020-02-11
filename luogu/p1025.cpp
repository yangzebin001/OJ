/*
 * @Date: 2020-02-11 17:25:08
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 17:42:41
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans;
void dfs(int cnt,int last,int t){
    
    if(t == k){
        if(cnt == n) ans++;
        return;
    }
    for(int i = last; i <= (n-cnt)/(k-t); i++){
        dfs(cnt+i,i,t+1);
    }
}
int main(){
    cin >> n >> k;
    dfs(0,1,0);
    cout << ans;
    return 0;
}

