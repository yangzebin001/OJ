#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
typedef long long LL;
LL n, a;
const int MAXN = 1e6+10;
LL x[MAXN], y[MAXN];
int main(){
    scanf("%lld%lld",&n,&a);
    for(int i = 0; i < a; i++){
        scanf("%lld%lld", &x[i], &y[i]);
    }
    sort(x,x+a);
    sort(y,y+a);
    int lenx = unique(x, x+a) - x;
    int leny = unique(y, y+a) - y;
    //n-lenx 为没有被覆盖的行 n-leny同理。
    printf("%lld", n*n - (n-lenx)*(n-leny));
    return 0;
}