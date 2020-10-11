/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 14:47:31 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-10 14:49:34
 */
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ans = n;
        int x;
        do{
            x = n%3;
            n /= 3;
            ans += n;
            n += x;
        }while(n >= 3);
        cout << ans << endl;
    }
    return 0;
}