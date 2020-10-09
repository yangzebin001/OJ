/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 08:43:21 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 09:38:39
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 5010;

struct e{
    int l,w;
}p[MAXN];
int vis[MAXN];
bool cmp(e &a, e &b){
    if(a.l == b.l) return a.w > b.w;
    return a.l > b.l;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].l >> p[i].w;
    }
    sort(p,p+n, cmp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int l = p[i].l, w = p[i].w;
        ans++;
        for(int j = i+1; j < n; j++){
            if(!vis[j]){
                if(p[j].l <= l && p[j].w <= w){
                    l = p[j].l;
                    w = p[j].w;
                    vis[j] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}