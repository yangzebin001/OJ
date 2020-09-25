#include<iostream>

using namespace std;

long long n,m;

int dfs(int n,int m){
    if(n == m) return 4*n;
    int minv = min(n,m);
    int dis = max(n,m)-minv;
    return dfs(dis, minv) + 4*minv;
}

int main(){
    scanf("%lld%lld",&n,&m);
    long long ans = 0;
    while(n && m){
        swap(n,m);
        ans += 4*m*(n/m);
        n%=m;
    }
    printf("%lld",ans);
    return 0;
}