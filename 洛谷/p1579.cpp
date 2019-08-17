#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool isPrime(int n){
    if( n <= 0) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return n != 1;
}

int main(){
    int n;
    scanf("%d",&n); 
    for(int i = 2; i < n; i++){
        for(int j = 2; j < n; j++){
            if(isPrime(i) && isPrime(j) && isPrime(n-i-j)){
                printf("%d %d %d",i,j,n-i-j);
                return 0;
            }
        }
    }
    return 0;
}