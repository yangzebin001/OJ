/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 15:12:58 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-10 15:14:02
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 1; i <= 99; i++){
        int ans = 0;
        for(int j = i; j <= 99; j++){
            ans += j;
            if(ans == 236){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}