/*
 * @Date: 2020-01-21 20:23:05
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-21 21:00:53
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int M[15][15];
int b[30],c[30],d[30];
vector<vector<int> > ans;
int n;
int cnt = 0;
bool vaild(int i,int j){
    return (!b[j] && !c[i+j] && !d[i-j+n]);
}
void dying(int i,int j){
    b[j] = 1;
    c[i+j] = 1;
    d[i-j+n] = 1;
}
void dying1(int i,int j){
    b[j] = 0;
    c[i+j] = 0;
    d[i-j+n] = 0;
}
void dfs(int t){
    if(t == n+1){
        cnt++;
        if(cnt <= 3){
            // for(int i = 1; i <= n; i++){
            //     for(int j = 1; j <= n; j++){
            //         printf("%d ",vis[i][j]);
            //     }
            //     printf("\n");
            // }
            for(int i = 1; i <= n; i++){
                if(i != 1) printf(" ");
                for(int j = 1; j <= n; j++){
                    if(M[i][j]) {
                        printf("%d",j);
                        break;
                    }
                }
            }
            printf("\n");
        }
        return ;
    }
    for(int i = 1; i <= n; i++){
        M[t][i] = t;
        if(vaild(t,i)){
            dying(t,i);
            dfs(t+1);
            dying1(t,i);
        }
        M[t][i] = 0;
    }
}


int main(){
    scanf("%d",&n);
    // if(n == 13){
    //     printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712\n");
    //     return 0;
    // }
    dfs(1);
    printf("%d",cnt);
    return 0;
}