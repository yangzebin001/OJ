#include<iostream>
#include<algorithm>
using namespace std;

int F[10000];

int getF(int a){
    return F[a] == a ? a : F[a] = getF(F[a]);
}

int _union(int a, int b){
    F[getF(a)] = getF(b);
}

bool issame(int a, int b){
    return getF(a) == getF(b);
}

int n,m,p;

int main(){

    cin >> n >> m >> p;
    for(int i = 0; i <= n; i++) F[i] = i;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        _union(a,b);
    }
    for(int i = 0;  i < p; i++){
        cin >> a >> b;
        if(issame(a,b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}