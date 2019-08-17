#include<iostream>
#include<cstdio>
typedef long long LL;
using namespace std;

int m[30][30][30];

int w(LL a, LL b,LL c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20,20,20);
    if(m[a][b][c]) return m[a][b][c];
    int ans = 0;
    if(a < b && b < c)
        ans = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else 
        ans = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    m[a][b][c] = ans;
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    LL a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    while(a != -1 || b != -1 || c != -1){
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));

        scanf("%lld%lld%lld",&a,&b,&c);
    }
    return 0;
}
