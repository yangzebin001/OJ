#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int chosen;
string arr = "";
void dfs(int k,int n,int chosen){
    if(k == n){
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]-'0');
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        if(!((chosen>>i) & 1)){
            arr += i+1+'0';
            dfs(k+1,n,chosen | (1 << i));
            arr.pop_back();
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    dfs(0,n,chosen);
    return 0;
}