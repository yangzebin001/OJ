/*
 * @Date: 2020-01-29 22:40:11
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 22:47:38
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2){
            printf("7");
            for(int i = 0; i < (n-3)/2; i++) printf("1");
        }else{
            for(int i = 0; i < n/2; i++) printf("1");
        }
        printf("\n");
    }
    return 0;
}