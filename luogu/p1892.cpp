#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int F[10010];

int getF(int a){
    return F[a] == a ? a : F[a] = getF(F[a]);
}

int _union(int a, int b){
    a = getF(a);
    b = getF(b);
    if(a != b) F[a] = b;
}
int n,m;
int main(){
    for(int i = 0; i < 10010; i++) F[i] = i;
    scanf("%d%d", &n, &m);
    while(m--){
        char a[2]; int b,c;
        scanf("%s%d%d",a,&b,&c);
        //a的敌人是b，b的敌人是a
        if(a[0] == 'E'){
            _union(b+n,c);
            _union(c+n,b);
        }else{
            _union(b,c);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(F[i] == i) ans++;
    }
    printf("%d",ans);
    return 0;
}