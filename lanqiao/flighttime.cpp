#include<bits/stdc++.h>

using namespace std;
char start[500];
int n;
int h1,m1,s1,h2,m2,s2;
int starttime, endtime;
void work(){
    if(start[strlen(start)-1] == ')'){
        if(start[strlen(start)-2] == '1'){
            h2+=24;
        }else if(start[strlen(start)-2] == '2'){
            h2+=24*2;
        }else if(start[strlen(start)-2] == '3'){
            h2+=24*3;
        }
    }
}
int dis(){
    sscanf(start,"%d:%d:%d %d:%d:%d", &h1,&m1,&s1,&h2,&m2,&s2);
    work();
    int t = 0;
    t += (h2-h1)*3600;
    t += (m2-m1)*60;
    t += (s2-s1);
    return t;
}

int main(){
    scanf("%d",&n);
    getchar();
    while(n--){
        fgets(start, 1000, stdin);
        start[strlen(start)-1] = '\0';
        starttime = dis();
        
        fgets(start, 1000, stdin);
        start[strlen(start)-1] = '\0';
        endtime = dis();
        int t = (endtime + starttime) /2;
        // printf("%d\n",t);
        printf("%02d:%02d:%02d\n", t/3600, t/60%60, t%60);
    }
    return 0;
}