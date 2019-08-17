#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
using namespace std;

const int MAXN = 1000100;
map<int,int> m;
int arr[MAXN];
int d[MAXN];
int N,I,H,R;
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&N,&I,&H,&R);
    for(int i = 1; i <= N; i++){
        arr[i] = H;
    }
    for(int i = 0; i < R; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(m[x] == y) continue;
        m[x] = y;
        if(x > y) swap(x,y);
            d[x+1] -= 1;
            d[y] += 1;
    }
    int q = 0;
    for(int i = 1; i <= N; i++){
        q += d[i];
        arr[i] += q;
        printf("%d\n",arr[i]);
    }
    return 0;
}
