#include<iostream>
#include<algorithm>

using namespace std;

int F[1010];

int getF(int a){
    return F[a] == a ? a : F[a] = getF(F[a]);
}

void _union(int a, int b){
    F[getF(a)] = getF(b);
}

int main(){

    int n, m;
    while(1){
    for(int i = 0 ; i < 1010; i++) F[i] = i;
        cin >> n;
        if(!n) break;
        cin >> m;
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            _union(a,b);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(F[i] == i) cnt++;
        cout << cnt-1 << endl;
    }
    return 0;
}