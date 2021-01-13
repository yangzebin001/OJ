#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1e6+10;
int n,k,x;
int f[MAXN];
int main(){
    cin>>n>>k;
    f[1] = 0;
    for(int i = 2; i <= n; i++){
        f[i] = (f[i-1]+k)%i;
    }
    cout << f[n] + 1 << endl;
    return 0;
}