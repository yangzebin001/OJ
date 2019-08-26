#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
int MOD = 1000000007;
int a,b,n;
map<LL,int> m;
LL dfs(LL n){
    if(m.count(n)) return m[n];
    
    if(n % 2 == 1) return m[n] = ((((n*n)%MOD*n)%MOD * b) %MOD + (((n*n)%MOD*(n-1))%MOD*a)%MOD)%MOD;
    LL c = dfs(n>>1)%MOD;
    m[n>>1] = c;
    return min( (((((n>>1)*(n>>1))%MOD*18)*a)%MOD +  ((c)%MOD*7)%MOD)%MOD, ((((n*n)%MOD*n)%MOD * b) %MOD + (((n*n)%MOD*(n-1))%MOD*a)%MOD)%MOD); 
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&a,&b);
        printf("%d\n",dfs(n*1L));
    }
    return 0;
}