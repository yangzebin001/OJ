#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000010];
int n,m;

int main(){
    cin >> n >> m;
    int len = n+m+1;
    for(int i = 0; i < len; i++){
        cin >> a[i];
    }
    sort(a,a+len);
    if(a[0] >= 0 && m) a[0] = -a[0]; 
    else{

        for(int i = 0; i < len && m; i++){
            if(a[i] < 0){
                a[i] = -a[i];
                m--;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < len; i++) ans += a[i];
    
    cout << ans;
    return 0;
}