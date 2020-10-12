/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 15:19:35 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-12 15:25:19
 */
#include<bits/stdc++.h>

using namespace std;
bool rui(int x){
    return (x % 4 == 0 && x % 100 != 0) || x%400 == 0;
}
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int y = 2014, m = 11, d = 9;
    int t = 1000;
    while(t--){
        d++;
        if(m == 2){
            if(d == months[m]+rui(y)+1){
                m++;
                d = 1;
            }
        }else if(d == months[m]+1){
            m++;
            d = 1;
            if(m == 13){
                m = 1;
                y++;
            }
        }
    }
    printf("%04d-%02d-%02d",y,m,d);
    return 0;
}