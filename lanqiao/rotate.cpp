/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-14 17:25:40 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-14 17:30:03
 */
#include<bits/stdc++.h>

using namespace std;
int a[110][110];
int b[110][110];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            b[j][n-i+1] = a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}