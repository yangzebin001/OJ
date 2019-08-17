#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 20;


char m[MAXN][MAXN];
int n,k;
int ans = 0;

bool judge(int x, int y){
    for(int i = 0; i < x; i++){
        if(m[i][y] == 'q') return false;
    }
    for(int i = 0; i < y; i++){
        if(m[x][i] == 'q') return false;
    }
    return true;
}

void dfs(int col, int k){
    if(k == 0){
        ans++;
        return;
    }
    if(col == n){
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(m[col][i] == '#' && judge(col,i)){
            m[col][i] = 'q';
            dfs(col+1,k-1);
            m[col][i] = '#';
        }
    }dfs(col+1,k);
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    while(n != -1 && k != -1){
        memset(m,0,sizeof(m));
        for(int i = 0; i < n; i++){
            scanf("%s",m[i]);
        }
        ans = 0;
        dfs(0,k);
        printf("%d\n",ans);
        scanf("%d%d",&n,&k);
    }
    return 0;
}
