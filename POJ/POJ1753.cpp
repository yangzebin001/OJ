#include<cstdio>
int chess[6][6] = {0};
int ans = 17;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void flip(int x, int y){
    chess[x][y]=!chess[x][y];
    for(int k = 0; k < 4; k++){
        int dx = x + d[k][0];
        int dy = y + d[k][1];
        if(0 <= dx && dx < 4 && 0 <= dy && dy < 4){
            chess[dx][dy] = !chess[dx][dy];
        }
    }
}

bool isALLCmp(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(chess[i][j] != chess[0][0]) return false;
        }
    }
    return true;
}


void dfs1(int i,int d){
    if(isALLCmp()){
        if(ans > d) ans = d;
        return;
    }
    if(i >= 16) return;
    dfs1(i+1,d);
    flip(i/4,i%4);
    dfs1(i+1,d+1);

    flip(i/4,i%4);
}


int main(){
    // freopen("in.txt","r",stdin);
    char c[6];
    for(int i = 0; i < 4; i++){
        scanf("%s",c);
        for(int j = 0; j < 4; j++){
            if(c[j] == 'b') chess[i][j] = 0;
            else chess[i][j] = 1;
        }
    }
    // flip(3,3);
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         if(chess[i][j] == false)printf("w");
    //         else printf("b");
    //     }
    //     printf("\n");
    // }
    dfs1(0,0);
    if (ans == 17 )
        printf ("Impossible\n");
    else 
        printf ("%d\n",ans);
    return 0;
}