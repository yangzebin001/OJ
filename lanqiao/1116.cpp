#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
char ip[100];
size_t  len = 100;
int main(){
    const char s[2] = ".";
    char *token;
    int read;
    while(fgets(ip, len, stdin) != NULL){
        token = strtok(ip, s);
        int flag = 0;
        while(token != NULL){
            // printf("%s1\n", token);
            int len = strlen(token);
            
            int num = 0, i;
            for(i = 0; i < len ; i++){
                if(token[i] == '\n' || token[i] == ' ') continue;
                if(token[i] > '9' || token[i] < '0'){
                    break;
                }else{
                    num = num * 10 + (token[i]-'0');
                    if(num > 255 || num < 0) break;
                }
            }
            if(i != len){
                flag = 1;
            }
            token = strtok(NULL, s);
        }
        if(flag){
            printf("N\n");
        }else{
            printf("Y\n");
        }
    }
    return 0;
}