/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 18:08:25 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 18:08:59
 */
#include<bits/stdc++.h>

using namespace std;


//求因数为5的个数
int main(){
    int x;
    int five = 0;
    for(int i = 0; i < 100; i++){
        cin >> x;
        while(x % 5 == 0){
            x /= 5;
            five++;
        }
    }
    cout << five << endl;
    // cout << 31 << endl;
    return 0;
}