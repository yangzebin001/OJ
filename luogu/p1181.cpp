/*
 * @Date: 2020-01-14 17:22:25
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 17:24:36
 */
#include<iostream>
using namespace std;

int sum = 0, ans = 0;
int main(){
    int a,n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a+sum > m){
            ans++;
            sum = a;
        }else{
            sum += a;
        }
    }
    if(sum) ans++;
    cout << ans;
    return 0;
}