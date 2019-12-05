#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int sum = 0;
    int price = 300;
    int cur = 0;
    for(int i = 1; i <= 12; i++){
        int a;
        scanf("%d",&a);
        cur += price;
        if(cur < a){
            printf("-%d",i);
            return 0;
        }
        cur -= a;
        sum += (cur/100)*100;
        cur %= 100;

    }
    printf("%.0f",sum * 1.2 + cur);
    return 0;
}