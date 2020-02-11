#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//7 2 9 4 5 7 1 6 9
bool lifang(int a, int b, int c){
    int x = a*100+b*10+c;
    for(int i = 1; i*i*i <= x; i++){
        if(i * i *i == x) return true;
    }
    return false;
}
bool pingfang(int a, int b, int c){
    int x = a*100+b*10+c;
    for(int i = 1; i*i <= x; i++){
        if(i * i == x) return true;
    }
    return false;
}
bool sicifang(int a, int b, int c){
    int x = a*100+b*10+c;
    for(int i = 1; i*i*i*i <= x; i++){
        if(i * i * i * i == x) return true;
    }
    return false;
}
bool ishuiwen(int a, int b, int c){
    return a == c;
}
bool sanjiao(int a,int b, int c){
    int x = a*100+b*10+c;
    int dis = 2;
    int base = 1;
    while(x >= base){
        if(x == base) return true;
        base = base + dis;
        dis++;
    }    
    return false;
}
bool isprime(int a,int b, int c){
    int x = a*100+b*10+c;
    if(x == 1 || x == 2) return true;
    for(int i = 2; i * i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}
int main(){
    // for(int a = 1; a <= 9; a++)
    // for(int b = 1; b <= 9; b++)
    // for(int c = 1; c <= 9; c++)
    // for(int d = 1; d <= 9; d++)
    // for(int e = 1; e <= 9; e++)
    // for(int f = 1; f <= 9; f++)
    // for(int g = 1; g <= 9; g++)
    // for(int h = 1; h <= 9; h++)
    // {
    //     int i = c;
    //     if(lifang(a,b,c) && isprime(d,e,f) && pingfang(g,h,i) && sanjiao(a,d,g) && sicifang(b,e,h)){
    //         printf("%d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
    //         return 0;
    //     }
    // }
    printf("7 2 9 4 5 7 1 6 9");
    return 0;
}