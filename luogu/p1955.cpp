/*
 * @Date: 2020-02-11 12:24:09
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 13:17:56
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int MAXN = 1000100;
int F[MAXN];
int samenum[MAXN][2];
int unsamenum[MAXN][2];
int getF(int x){
    return F[x] == -1 ? x : F[x] = getF(F[x]); 
}
bool issame(int x, int y){
    return getF(x) == getF(y);
}
void _union(int x, int y){
    x = getF(x);
    y = getF(y);
    if(x != y) F[x] = y;
}
int t;
unordered_map<int,int> M;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        M.clear();
        t = 0;
        int s1 = 0, s2 = 0;
        memset(F,-1,sizeof(F));
        int n,iserror = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            int x,y,e;
            scanf("%d%d%d",&x,&y,&e);
            if(!M.count(x)) M[x] = t++;
            if(!M.count(y)) M[y] = t++;
            if(e){
                samenum[s1][0] = x,
                samenum[s1++][1] = y;
            }else{
                unsamenum[s2][0] = x,
                unsamenum[s2++][1] = y;
            }
        }
        for(int i = 0; i < s1; i++){
            _union(M[samenum[i][0]],M[samenum[i][1]]);
        }
        for(int i = 0; i < s2; i++){
            if(issame(M[unsamenum[i][0]],M[unsamenum[i][1]])){
                iserror = 1;
            }
        }
        if(iserror) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}