#include<iostream>
using namespace std;
int n,pre[300], g[300][300], w[300], f[300], ans, ans_idx;

void print(int x){
    if(pre[x] == 0) {
        cout << x ;
        return;
    }
    print(pre[x]);
    cout << " " << x;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            cin >> g[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[j][i] && f[j] > f[i]){
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += w[i];
        if(f[i] > ans){
            ans = f[i];
            ans_idx = i;
        }
    }
    print(ans_idx);
    cout << endl << ans << endl;
    return 0;
}