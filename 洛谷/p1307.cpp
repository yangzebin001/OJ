#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int getNum(char *s){
    int ans = 0;
    for(int i = strlen(s)-1; i >= 0; i--){
        ans *= 10;
        ans += s[i]-'0';
    }
    return ans;
}

char s[1000];
int main(){
    scanf("%s",s);
    int flag = 0;
    if(s[0] == '-'){
        flag = -1;
    }else if(s[0] == '+') flag = 1;
    int i = 0,len = strlen(s);
    if(flag) i++;
    while(i < len && s[i] == '0') i++;
    if(i >= len) printf("0");
    else printf("%d",flag ? (flag * getNum(s+i)) : getNum(s+i));
    return 0;
}
