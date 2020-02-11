/*
 * @Date: 2020-02-10 19:09:33
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 20:09:48
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_set>
using namespace std;
const int MAXN = 4e5+10;
int attack[MAXN];
vector<int> edge[MAXN];
int ans[MAXN],c;
int n,m;
int F[MAXN];
unordered_set<int> canattack;
int getF(int x){
    return F[x] == -1 ? x : F[x] = getF(F[x]);
}
bool _union(int a,int b){
    a = getF(a);
    b = getF(b);
    if(a != b){ 
        F[a] = b;
        return true;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(F,-1,sizeof(F));
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int k;
    scanf("%d",&k);
    int cnt = n-k;
    for(int i = 0; i < k; i++){
        scanf("%d",&attack[i]);
        canattack.insert(attack[i]);
    }
    for(int i = 0; i < n; i++){
        if(!canattack.count(i)){
            for(int j = 0; j < edge[i].size(); j++){
                if(canattack.count(edge[i][j])) continue;
                if(_union(i,edge[i][j])) cnt--;
            }
        }
    }
    
    ans[c++] = cnt;
    for(int i = k-1; i >= 0; i--){
        int t = attack[i];
        cnt++;
        canattack.erase(t);
        for(int j = 0; j < edge[t].size(); j++){
                if(canattack.count(edge[t][j])) continue;
                if(_union(t,edge[t][j])) cnt--;;
            }
        ans[c++] = cnt;
    }
    for(int i = c-1; i >= 0; i--){
        printf("%d\n",ans[i]);
    }
    return 0;
}