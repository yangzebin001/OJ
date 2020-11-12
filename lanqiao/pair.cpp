#include<bits/stdc++.h>

using namespace std;
int a[] = {2,3,5,8};
int b[] = {1,4,6,7};
int ans;
int main(){
    // do{
        do{
            long long c = 0,d = 0;
            for(int i = 0; i < 4; i++){
                c += (a[i]*10+b[i])*(a[i]*10+b[i]);
            }
            for(int i = 0; i < 4; i++){
                d += (b[i]*10+a[i])*(b[i]*10+a[i]);
            }
            if(c == d){
                ans++;
                cout << c << endl;
            }
        }while(next_permutation(b,b+4));
        b[0] = 1;
        b[1] = 4;
        b[2] = 6;
        b[3] = 7;
    // }while(next_permutation(a,a+4));
    cout << ans;
    return 0;
}