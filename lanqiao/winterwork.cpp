#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[13];
    int ans = 0;
    for(int i = 0; i < 13; i++) a[i] = i+1;
    do{
        if(a[0]+a[1] == a[2]
            && a[3]-a[4] == a[5]
            && a[6]*a[7] == a[8]
            && a[11]*a[10] == a[9]
        ){
            ans++;
        }
    }while(next_permutation(a,a+13));
    cout << ans;
    return 0;
}