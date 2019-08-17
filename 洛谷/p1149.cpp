#include<iostream>
#include<vector>
#include<cstdio>
int matchstick[10] = {6,2,5,5,4,5,6,3,7,6};

// int d[100];

int n;
int ans;

int getms(int num){
    int ans = 0;
    if(num == 0) return matchstick[0];
    while(num){
        ans += matchstick[num%10];
        num/=10;
    }
    return ans;
}

int check(int a,int b, int c){
    return getms(a) + getms(b) + getms(c);
}


int main(){
    // for(int i = 0; i < 100; i++) d[i] = i;
    scanf("%d",&n);
    n-=4;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            int a = i + j;
            if(check(i,j,a) == n) ans ++;
        }
    }
    printf("%d",ans);
    return 0;
}