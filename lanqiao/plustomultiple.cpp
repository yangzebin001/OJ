/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 17:07:43 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-12 17:17:18
 */
#include<bits/stdc++.h>

using namespace std;
int sum[50];
int main(){
    for(int i = 1; i <= 49; i++){
        sum[i] = sum[i-1]+i;
    }
    for(int i = 1; i <= 48; i++){
        for(int j = i+1; j <= 48; j++){
            int a = sum[i-1];
            int b = sum[j-1]-sum[i+1];
            int c = sum[49]-sum[j+1]; 
            if(a+b+c+i*(i+1)+j*(j+1) == 2015){
                printf("%d %d\n",i,j);
            }
            // if(i == 10 && j == 27){
            //     cout << a+b+c+i*(i+1)+j*(j+1) << endl;
            // }
        }
    }
    return 0;
}