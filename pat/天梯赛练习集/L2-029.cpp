/*
 * @Date: 2019-11-19 20:06:32
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-19 21:01:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 1e4+10;
int cnt[MAXN],F[MAXN];
int vis[MAXN];
map<int,int> M;
int A,B;
bool isprime(int t){
    for(int i = 2; i*i <= t; i++){
        if(t%i == 0) return false;
    }
    return t != 1;
}
int getnum(int t){
    int ans = 0;
    while(t){
        ans += (t%10)*(t%10);
        t /= 10;
    }
    return ans;
}

int dfs(int t){
    if(t == 1) return 0;
    if(vis[t] && cnt[t] == 0) return 1e5+10;
    vis[t] = 1;
    if(cnt[t]) return cnt[t];
    int c = getnum(t);
    cnt[t] = dfs(c)+1;
    // cout << cnt[t] << endl;
    F[c] = t;
    return cnt[t];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&A,&B);
    for(int i = A; i <= B; i++){
        dfs(i);
    }
    for(int i = A; i <= B; i++){
        // printf("%d ",F[i]);
        if(cnt[i] > 1e5) continue;
        if(F[i] >= A && F[i] <= B) continue;
        if(isprime(i)){
            M[i] = cnt[i]*2;
        }else{
            M[i] = cnt[i];
        }
    }
    map<int,int>::iterator it;
    for(it = M.begin(); it != M.end(); it++){
        printf("%d %d\n",it->first,it->second);
    }
    if(M.size() == 0) printf("SAD");
    return 0;
}