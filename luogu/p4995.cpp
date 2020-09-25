#include<iostream>
#include<algorithm>

using namespace std;
long long n;
int arr[1000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int l = 0, r = n-1;
    int flag = 1;
    long long ans = arr[n-1] * arr[n-1];
    while(l < r){
        ans += (arr[r] - arr[l]) * (arr[r] - arr[l]);
        if(flag) r--;
        else l++;
        flag = !flag;
    }
    cout << ans;
    return 0;
}