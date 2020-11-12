#include<bits/stdc++.h>

using namespace std;
long long f[1010];
int main(){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 50; i++){
        f[i] = f[i-1]+f[i-2];
    }
    int n;
    cin >> n;
    if(n < 50){
        printf("%.8f\n",f[n]*1.0/f[n+1]);
    }else{
        printf("%.8f\n",f[50-1]*1.0/f[50]);
    }
    return 0;
}