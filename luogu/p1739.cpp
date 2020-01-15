/*
 * @Date: 2019-12-02 21:17:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-16 09:57:14
 */
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    char c;
    int sum = 0;
    while(scanf("%c",&c) && c !='@'){
        if(c == '(') sum++;
        if(c == ')') sum--;
        if(sum < 0){
            printf("NO");
            return 0;
        }
    }
    if(sum == 0) printf("YES");
    else printf("NO");
    return 0;
}