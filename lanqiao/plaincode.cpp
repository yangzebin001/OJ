/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-13 09:28:55 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-13 09:30:35
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    int t = 10;
    while(t--){

        for(int i = 0; i < 16; i++){
            scanf("%d%d",&a,&b);
            for(int j = 7; j >= 0; j--){
                if(a&(1<<j)) printf("*");
                else printf(" ");
            }
            for(int j = 7; j >= 0; j--){
                if(b&(1<<j)) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    long long ans = 1;
    for(int i = 1; i < 10; i++){
        ans *= 9;
    }
    cout << ans;
    
    return 0;
}