#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 100100;
const int INF = 0x3f3f3f3f;
int arr[MAXN];
int ans = INF;

int N,S;
void solve(){
    int m = 0;
    for(int i = 1; i <= N; i++){
        while(arr[i]-arr[m] >= S){
            ans = min(ans,i-m);
            m++;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        ans = INF;
        memset(arr,0,sizeof(arr));
        scanf("%d%d",&N,&S);
        for(int i = 1; i <= N; i++){
            int d;
            scanf("%d",&d);
            arr[i] = arr[i-1];
            arr[i] += d;
        }
        solve();
        if(ans == INF) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}