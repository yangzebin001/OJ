#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef unsigned long long ULL;

int k = 0;
int n;
void dfs(ULL num,int i){
    if(k == 1) return;
    if(num % n == 0){
        k = 1;
        printf("%llu,\n",num);
        return;
    }
    if(i == 19) return;
    dfs(num*10,i+1);
    dfs(num*10+1,i+1);
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int i = 1;
    while(i <= 200){
        n = i++;
        k = 0;
        dfs(1,0);
    }
    return 0;
}