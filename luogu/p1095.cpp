#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int M,S,T;
int s1,s2,time1;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&M,&S,&T);
    while(s1 < S && time1 < T){
        //能跳就跳，否则歇着。
        if(M >= 10){
            s2 += 60,M-=10;
        }else{
            M+=4;
        }
        //同时考虑跑的情况，跑的时候不费蓝也不增加蓝。
        s1 += 17;
        //看哪个大。
        s1 = max(s1,s2);
        time1++;
    }
    if(s1 < S){
        printf("No\n%d",s1);
    }else{
        printf("Yes\n%d",time1);
    }
    return 0;
}