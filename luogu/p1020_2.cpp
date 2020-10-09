/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-09 09:33:27 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-09 09:38:24
 */

#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN = 100010;
int dp1[MAXN],dp2[MAXN];
int len1, len2;
int main(){
    int x;
    while(cin >> x){
        int pos = upper_bound(dp1,dp1+len1,x,greater<int>()) - dp1;
        if(pos == len1) dp1[len1++] = x;
        else dp1[pos] = x;

        pos = lower_bound(dp2,dp2+len2,x) - dp2;
        if(pos == len2) dp2[len2++] = x;
        else dp2[pos] = x;
    }
    cout << len1 << endl << len2 << endl;
    return 0;
}