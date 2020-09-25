#include<iostream>
#include<cstdio>

using namespace std;
int n;
char c;
int main(){
    scanf("%d", &n);
    getchar();
    while(1){
        c = getchar();
        if(c == EOF) break;
        if(n){
            if(c == '\n' && n) n--, printf("\n\n");
            else{
                putchar(c);
            }
            
        }else{
            if(c == '\n' || c == ' '){
                printf("\n\n");
            }else{
                putchar(c);
            }
        }
        
    }
    return 0;
}