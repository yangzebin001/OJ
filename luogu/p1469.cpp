#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x,a;
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a);
        x ^= a;
    } 
    printf("%d",x);
    return 0;
}