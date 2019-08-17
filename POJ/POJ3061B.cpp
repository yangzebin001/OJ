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
    int sum = 0;
    int l = 0;
    for(int i = 1; i <= N; i++){
        sum += arr[i];
        while(sum-arr[l] >= S){
            ans = min(ans,i-l);
            sum -= arr[l];
            l++;
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
            scanf("%d",&arr[i]);
        }
        solve();
        if(ans == INF) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}