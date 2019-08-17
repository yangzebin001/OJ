#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int dx[16],ans[16];
int ansn = 40;
int state;


void flip(int i, int j){
    for(int k = 0; k < 4; k++){
        state = state ^ (1<< (i*4+k));
        state = state ^ (1 << (k*4+j));
    }
    state = state ^ (1 << (i*4+j));
}

//d:翻转的次数，s:要翻转的序号
void dfs(int d, int s){
    if(!state){
        //更新结果
        ansn = min(ansn,d);
        for(int i = 0; i < ansn; i++){
            ans[i] = dx[i];
        }
    }
    if(s >= 16) return;
    dfs(d,s+1);
    //翻转
    flip(s/4,s%4);
    //保留翻转的位置
    dx[d] = 1 << s;
    dfs(d+1,s+1);
    //回溯
    flip(s/4,s%4);
    dx[d] = 0;
}
int Pos(int a){
    int ans = 0;
    while(a){
        ans++;
        a >>= 1;
    }
    return ans;
}
int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            char c;
            scanf("%c",&c);
            // m[i][j] = c == '+' ? 1 : 0;
            if(c == '+')
                state = state | (1 << (i*4+j));
        }
        getchar();
    }
    dfs(0,0);
    printf("%d\n",ansn);
    for(int i = 0; i < ansn; i++){
        int a  = Pos(ans[i])-1;
        printf("%d %d\n",a/4+1,a%4+1);
    }
    return 0;
}