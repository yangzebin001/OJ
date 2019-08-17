#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int m[4][4];
int dx[16],dy[16],ans[16][2];
int ansn = 40;
bool isComplete(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(m[i][j] == 1) return false;
        }
    }
    return true;
}

void flip(int i, int j){
    for(int k = 0; k < 4; k++){
        m[k][j] = !m[k][j];
        m[i][k] = !m[i][k];
    }
    //m[i][j]被翻转了两次，再翻转抵消一次。
    m[i][j] = !m[i][j];
}

//d:翻转的次数，s:要翻转的序号
void dfs(int d, int s){
    if(isComplete()){
        ansn = min(ansn,d);
        for(int i = 0; i < ansn; i++){
            ans[i][0] = dx[i];
            ans[i][1] = dy[i];
        }
    }
    if(s >= 16) return;
    dfs(d,s+1);
    flip(s/4,s%4);
    dx[d] = s/4;
    dy[d] = s%4;
    dfs(d+1,s+1);
    flip(s/4,s%4);
    dx[d] = 0;
    dy[d] = 0;
}
int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            char c;
            scanf("%c",&c);
            m[i][j] = c == '+' ? 1 : 0;
        }
        getchar();
    }
    dfs(0,0);
    printf("%d\n",ansn);
    for(int i = 0; i < ansn; i++){
        printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
    }
    return 0;
}