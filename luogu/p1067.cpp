#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int flag = 1;
    for(int i = n; i >= 0; i--){
        int a;
        scanf("%d",&a);
        if(a == 0) continue;
        if(flag){
            if(a == -1){
                printf("-");
            }else if(a != 1){
                printf("%d",a);
            }
            flag = 0;
        }else{
            if(a == 1 && i != 0) printf("+");
            else if(a == -1 && i != 0) printf("-");
            else if(a > 0) printf("+%d",a);
            else if(a < 0) printf("%d",a);
        }
        if(i == 1){
            printf("x");
        }else if(i != 0){
            printf("x^%d",i);
        }
    }
    return 0;
}