/*
 * @Date: 2020-01-25 12:41:15
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 12:44:59
 */
#include<iostream>
#include<cstdio>
using namespace std;
//寻找 (N+1)/2 次的元素
int main(){
    int n;
    while(~scanf("%d",&n)){
        int cnt = 0;
        int res = 0;
        for(int i = 1; i <= n; i++){
            int a; scanf("%d",&a);
            if(cnt > 0){
                if(res == a) cnt++;
                else cnt--;
            }
            if(cnt == 0) cnt++,res = a;
        }
        printf("%d\n",res);
    }
    
    return 0;
}