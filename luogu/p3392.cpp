#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cctype>
#include<climits>
using namespace std;

string square;
int n,m, ans = INT_MAX;
int w[55], b[55], r[55];
int check(char c){
    int tot = 0;
    for(int i = 0; i < m; i++){
        if(square[i] != c) tot++;
    }
    return tot;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> square;
        w[i] = w[i-1] + check('W');
        b[i] = b[i-1] + check('B');
        r[i] = r[i-1] + check('R');
    }
    for(int i = 1; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            ans = min(ans, w[i] + b[j]-b[i] + r[n]-r[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}