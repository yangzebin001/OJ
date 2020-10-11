#include<bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}
int main(){
    int base = 1<<20;
    int a = 0, b = 1;
    for(int i = 1; i <= 20; i++){
        a += base/b;  //分子之和（以1<<20为底）
        b <<= 1;
    }
    base = gcd(a,b);  //通项
    printf("%d/%d\n",a/base,b/base);
    return 0;
}