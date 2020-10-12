/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-12 19:46:02 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-12 20:06:15
 */
#include<bits/stdc++.h>

using namespace std;
int w,n,m;
int main(){
    while(cin >> w >> n >> m){
    int r1 = n / w + (n%w != 0);
    int r2 = m / w + (m%w != 0);
    int c1,c2;
    if(r1%2){ //从左到右
        c1 = w - (r1*w-n); 
    }else{
        c1 = r1*w-n+1;
    }
    if(r2%2){ //从左到右
        c2 = w - (r2*w-m);
    }else{
        c2 = r2*w-m+1;
    }
    // printf("%d %d %d %d\n", r1,c1,r2,c2);
    printf("%d\n",abs(c1-c2) + abs(r1-r2));
    }
    return 0;
}