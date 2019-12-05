#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct apple{
    int h,s;
};
const int MAXN = 5005;
apple app[MAXN];
bool cmp(const apple &a, const apple &b){
    if(a.s == b.s) return a.h < b.h;
    return a.s < b.s;
}

int main(){
    int n,s;
    int a,b;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    for(int i = 0; i < n; i++){
        int h,s;
        scanf("%d%d",&h,&s);
        app[i].h = h;
        app[i].s = s;
    }
    sort(app,app+n,cmp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s == 0) break;
        if(s < app[i].s)break;
        if(a+b < app[i].h) continue;
        s -= app[i].s;
        ans++;
    }
    printf("%d",ans);
    return 0;
}

