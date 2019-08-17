#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int m;
int ans = 26;
void flip(int k){
    int i = k / 5,j = k % 5;
    m ^= 1 << k;
    if(j-1 >= 0) m ^= (1 << (i * 5 + (j-1)));
    if(j+1 < 5) m ^= (1 << (i *5 + (j+1)));
    if(i-1 >= 0) m ^= (1 << ((i-1) *5 + j));
    if(i+1 < 5) m ^= (1 << ((i+1) *5 + j));
}

void dfs(int k,int d){
    if(m == (1<<25)-1){
        ans = min(ans,d);
        return;
    }
    if(k >= 26) return;
    dfs(k+1,d);
    flip(k);
    dfs(k+1,d+1);
    flip(k);
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char c[10];
        m = 0;
        ans = 26;
        for(int i = 0; i < 5; i++){
            scanf("%s",c);
            for(int j = 0; j < 5; j++){
                if(c[j] == '1') m |= (1 << (i*5+j));
            }
            printf("%s\n",c);
            getchar();
        }
        printf("%#x\n",m);
        dfs(0,0);
        if(ans > 6) ans = -1;
        printf("%d\n",ans);
    }
    
    return 0;
}