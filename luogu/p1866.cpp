#include<iostream>
#include<algorithm>
using namespace std;
int arr[100];
int main(){
    int n,a;
    cin >> n;
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++){
        ans = ans * (arr[i] - i+1) % 1000000007;
    }
    cout << ans;
    return 0;
}