/*
 * @Date: 2019-09-07 22:08:33
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-08 22:07:19
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

typedef struct letter{
    int len;
    char s[17];
}let;

let str[10017];

void rep(char *s, char *ss){
    int len = strlen(s);
    int flag = 0;
    int i = 0, j = 0;
    while(i < len){
        if(flag >= 2) break;
        if(s[i] != ss[j]) flag++;
        i++,j++;
    }
    if(flag < 2) printf(" %s",ss);
}

void del(char *s, char *ss,int p){
    int len = strlen(s);
    int flag = 0, i = 0, j = 0;
    while(i < len){
        if(flag >= 2) break;
        if(s[i] == ss[j]){ i++;j++;}
        else{i++;flag++;}
    }
    if(flag < 2) printf(" %s", p ? s : ss);
}




int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ss[17];
    int k = 0;
    while(~scanf("%s",str[k].s)){
        str[k].len = strlen(str[k].s);
        if(str[k].s[0] == '#') break;
        k++;
    }
    while(~scanf("%s",ss)){
        if(ss[0] == '#') break;
        int len = strlen(ss);
        int flag = 0;
        for(int i = 0; i < k; i++){
            if(!strcmp(ss,str[i].s)){
                printf("%s is correct\n",ss);
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        printf("%s:",ss);
        for(int i = 0; i < k; i++){
            if(len == str[i].len){
                rep(ss,str[i].s);
            }else if(len == str[i].len+1){
                del(ss,str[i].s,0);
            }else if(len == str[i].len-1){
                del(str[i].s,ss,1);
            }
        }
        printf("\n");
    }
    return 0;
}