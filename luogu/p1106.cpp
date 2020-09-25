#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
char s[1000];
int main(){
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int len = strlen(s);
    for(int i = 1; i < len; i++){
        if(s[i] < s[i-1]){
            for(int j = i-1; j < len-1; j++){
                s[j] = s[j+1];
            }
            k--;
            len--;
            i = 0;
        }
        if(!k) break;
    }
    len -= k;
    int i = 0;
    s[len] = '\0';
    while(i < len && s[i] == '0') i++;
    if(i == len) printf("0");
    else printf("%s", s+i);
    return 0;
}