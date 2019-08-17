#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double t[110];
int main(){
    freopen("in.txt","r",stdin);
    double x = 7.0;
    t[1] = x;
    for(int i = 2; i <= 105; i++){
        x = x * 0.98;
        t[i] = t[i-1] + x; 
    }
    int a,b;
    scanf("%d%d",&a,&b);
    // if(a == 0){
    //     printf("n\n");
    //     return 0;
    // }
    for(int i = 0; i <= 109; i++){
        if(t[i] > a-b){
            if(t[i+1] > a+b){
                printf("n\n");
                return 0;
            }else{
                printf("y\n");
                return 0;
            }
        }
    }
    return 0;
}