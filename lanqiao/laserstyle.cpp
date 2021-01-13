#include<bits/stdc++.h>

using namespace std;
int f[40][2];
int main(){
    f[1][0] = 1;
    f[1][1] = 1;
    for(int i = 2; i <= 30; i++){
        f[i][0] = f[i-1][0] + f[i-1][1];
        f[i][1] = f[i-1][0];
    }
    cout << f[2][0] + f[2][1];
    return 0;
}