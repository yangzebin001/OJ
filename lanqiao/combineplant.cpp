#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e6+10;
int f[MAXN];
int getf(int x){
    return f[x] == x ? x : f[x] = getf(f[x]);
}

void uni(int a, int b){
    a = getf(a), b = getf(b);
    if(a != b) f[a] = b;
}

int main(){
    for(int i = 0; i < MAXN; i++) f[i] = i;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < k; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        uni(a,b);
    }
    int ans = 0;
    for(int i = 1; i <= n*m; i++){
        if(f[i] == i) ans++;
    }
    cout << ans;
    return 0;
}