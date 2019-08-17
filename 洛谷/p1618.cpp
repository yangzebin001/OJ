#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int A,B,C;

int check(int a,int b,int c){
    if(a / 100 >= 10 || b / 100 >= 10 || c / 100 >= 10) return false;
    int vis[10] = {0};
    while(a){
        vis[a%10]++;
        a /= 10;
    }
    while(b){
        vis[b%10]++;
        b /= 10;
    }
    while(c){
        vis[c%10]++;
        c /= 10;
    }
    for(int i = 1; i < 10; i++){
        if(vis[i] != 1) return false;
    }
    return true;
}

int main(){
    int flag = 0;
    scanf("%d%d%d",&A,&B,&C);
    if(A < 1){
         printf("No!!!");
         return 0;
    }
    for(int i = 123; i < 987; i++){
        int a = i,b,c;
        // int j = a / A;
        b = B * a / A;
        c = C * a / A;
        if(check(a,b,c)){
            flag = 1;
            printf("%d %d %d\n",a,b,c);
        }
    }
    if(flag == 0) printf("No!!!");
    return 0;
}