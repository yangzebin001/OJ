/*
 * @Date: 2020-01-22 23:21:21
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 23:46:49
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
void solve(int n){
    if(n < 24){
        printf("NO\n");
        return;
    }
    int nn = sqrt(n);
    for(int i = 2; i <= nn; i++){
        for(int j = i+1; j <= nn; j++){
            int k = n/(i*j);
            if(i != k && j != k && n % i == 0 && n % j == 0 && n %k == 0 && i * j * k == n){
                printf("YES\n%d %d %d\n",i,j,k);
                return;
            }
        }
    }
    printf("NO\n");
    
}

int main(){
    // freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}