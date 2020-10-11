#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000010];
int n,m;

bool cmp(int a, int b){
    return abs(a) > abs(b);
}

int main(){
    cin >> n >> m;
    int len = n+m+1;
    for(int i = 0; i < len; i++){
        cin >> a[i];
    }
    sort(a,a+len, cmp);
    for(int i = 0; i < len && m; i++){
        if(a[i] < 0){
            a[i] = -a[i];
            m--;
        }
    }

    if(m){
        for(int i = len-1; i >= 0 && m; i--){
            a[i] = -a[i];
            m--;
        }
    }
    long long ans = 0;
    for(int i = 0; i < len; i++) ans += a[i];
    
    cout << ans;
    return 0;
}