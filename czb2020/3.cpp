#include<iostream>
#include<algorithm>

using namespace std;

struct p{
    int id;
    double t,k;
}P[500010];

int cmp(p &a, p &b){
    if(a.t * a.k == b.t*b.k){
        if(a.t == b.t){
            return a.id < b.id;
        }else{
            return a.t > b.t;
        }
    }else{
        return a.t * a.k > b.t*b.k;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> P[i].t >> P[i].k;
        P[i].id = i;
    }
    sort(P+1,P+n+1,cmp);

    for(int i = 1; i <= n; i++){
        if(i > 1) cout << " ";
        cout << P[i].id;
    }

    return 0;
}