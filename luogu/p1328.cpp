/*
 * @Date: 2019-08-31 20:29:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-31 20:44:32
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 205;
int A[MAXN];
int B[MAXN];
int ansA,ansB;
int N,NA,NB;

void solve(int a,int b){
    if(a-b == -4){ansB++;}
    if(a-b == -3){
        if(a == 4 || b == 4){ansB++;}else{ansA++;}
    }
    if(a-b == -2){ansA++;}
    if(a-b == -1){
        if(a == 4 || b == 4){ansA++;}else{ansB++;}
    }

    
    if(a-b == 4){ansA++;}
    if(a-b == 3){
        if(a == 4 || b == 4){ansA++;}else{ansB++;}
    }
    if(a-b == 2){ansB++;}
    if(a-b == 1){
        if(a == 4 || b == 4){ansB++;}else{ansA++;}
    }
    // printf("%d %d\n",ansA,ansB);
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&NA,&NB);
    for(int i = 0; i < NA; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0; i < NB; i++){
        scanf("%d",&B[i]);
    }
    for(int i = 0; i < N; i++){
        solve(A[i%NA],B[i%NB]);
    }
    printf("%d %d\n",ansA,ansB);
    return 0;
}