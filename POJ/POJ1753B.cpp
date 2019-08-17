#include<cstdio>
int ans = 17;
int state;

void flip(int x){
    state = state ^ (1 << x);
    int i = x/4, j = x % 4;
    if(j-1 >=0 && i*4 + j-1 >= 0) state = state ^ (1 << (i * 4 + (j-1)));
    if(j+1 < 4 && i*4 + j+1 < 16) state = state ^ (1 << (i * 4 + (j+1)));
    if(i-1 >=0 && (i-1)*4 + j >= 0) state = state ^ (1 << ((i-1)*4 + j));
    if(i+1 < 4 && (i+1)*4 + j < 16) state = state ^ (1 << ((i+1)*4 + j));
}

bool isALLCmp(){
    if(state == 0) return true;
    if(state + 1 == (1<<16)) return true;
    return false;
}


void dfs1(int i,int d){
    if(isALLCmp()){
        if(ans > d) ans = d;
        return;
    }
    if(i >= 16) return;
    dfs1(i+1,d);
    flip(i);
    dfs1(i+1,d+1);
    flip(i);
}


int main(){
    // freopen("in.txt","r",stdin);
    char c[6];
    for(int i = 0; i < 4; i++){
        scanf("%s",c);
        for(int j = 0; j < 4; j++){
            if(c[j] == 'b') state = state | (1 << (i*4+j));
        }
    }
    // printf("%#x\n",state);
    dfs1(0,0);
    if (ans == 17 )
        printf ("Impossible\n");
    else 
        printf ("%d\n",ans);
    return 0;
}