/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-11 16:54:03 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-11 17:04:12
 */
#include<bits/stdc++.h>

using namespace std;
const int INF = 10010;
int f[INF];
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int n,x;
int ans;
int main(){
    int t = 0;
    cin >> n;
    f[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(!t) t = x;
        else t = gcd(t,x);
        for(int j = x; j < INF; j++){
            f[j] |= f[j-x];
        }
    }
    if(t != 1) printf("INF\n"); //如果同质，是凑不完的。
    else{
        for(int i = 1; i < INF; i++){
            if(!f[i]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}