/*
 * @Date: 2020-02-11 12:17:37
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 12:18:36
 */
/*
 * @Date: 2020-02-10 18:22:29
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 18:55:46
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 5e4+10;

int F[MAXN*3];
int getF(int x){
    return F[x] == -1 ? x : F[x] = getF(F[x]);
}
void _union(int x, int y){
    x = getF(x);
    y = getF(y);
    if(x != y) F[x] = y;
}
bool same(int x, int y){
    return getF(x) == getF(y);
}
int n,m,ans;
int main(){
    memset(F,-1,sizeof(F));
    scanf("%d%d",&n,&m);
    int type, a,b;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&type,&a,&b);
        a--,b--;
        if(a >= n || b >= n || a < 0 || b < 0){
            ans++;
            continue;
        }
        if(type == 1){
            if(same(a,b+n) || same(a,b+2*n)) ans++;
            else{
                _union(a,b);
                _union(a+n,b+n);
                _union(a+2*n,b+2*n);
            }
            
        }else if(type == 2){
            if(same(a,b) || same(a,b+2*n)) ans++;
            else{
                _union(a,b+n);
                _union(a+n,b+2*n);
                _union(a+2*n,b);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}