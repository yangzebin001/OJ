#include<iostream>

using namespace std;
const int MAXN = 1e5+10;
long long n,x,ans;
int arr[MAXN];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(arr[0] > x) ans += arr[0]-x, arr[0] = x;
    for(int i = 1; i < n; i++){
        if(arr[i] + arr[i-1] > x){
            int rest = arr[i] + arr[i-1] - x;
            ans += rest;
            arr[i] -= rest;
        }
    }
    cout << ans;
    return 0;
}