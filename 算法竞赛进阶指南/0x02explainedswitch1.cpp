#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;

char m[10][10];
int ans = INF;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
void flip(int x,int y){
    for(int i = 0; i <5; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi >= 0 && xi < 5 && yi >= 0 && yi < 5){
            m[xi][yi] ^= 1;
        }
    }
}

void solve(){
    char backup[10][10];
    int res = 0;
    memcpy(backup,m,sizeof(m));
    for(int i = 0; i < 1 << 5; i++){
        res = 0;
        for(int j = 0; j < 5; j++){
            if(i >> j & 1){
                res++;
                flip(0,j);
            }
        }
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 5; k++){
                if(m[j][k] == '0'){
                    flip(j+1,k);
                    res++;
                }
            }
        }
        bool flag = true;
        for(int j = 0; j < 5; j++){
            if(m[4][j] == '0'){
                flag = false;
                break;
            }
        }
        if(flag) ans = min(ans,res);
        memcpy(m,backup,sizeof(backup));    
    }

}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        ans = INF;
        for(int i = 0; i < 5; i++){
            scanf("%s",m[i]);
            // printf("%s\n",m[i]);
        }
        solve();
        if(ans > 6) ans = -1;
        printf("%d\n",ans);
    }
    
    return 0;
}