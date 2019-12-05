#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 100009;

int m[MAXN][5];


int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a,b,g,k;
        scanf("%d%d%d%d",&a,&b,&g,&k);
        m[i][0] = a;
        m[i][1] = a+g;
        m[i][2] = b;
        m[i][3] = b+k;
        m[i][4] = i+1;
    }
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i = n-1; i >= 0; i--){
        if(x >= m[i][0] && x <= m[i][1] && y >= m[i][2] && y <= m[i][3]){
            printf("%d",m[i][4]);
            return 0;
        }
    }
    printf("%d",-1);

    return 0;
}