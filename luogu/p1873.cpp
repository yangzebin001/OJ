#include<iostream>
#include<algorithm>

using namespace std;
long long n,m;
long long arr[1000010];
bool check(int mid){
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > mid) {
            ans += arr[i] - mid;
        }
    }
    return ans >= m;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long l = 1, r = 1000000000;
    while(l < r){
        long long mid = (l+r+1)>>1;
        if(check(mid)){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    cout << l << endl;
    return 0;
}