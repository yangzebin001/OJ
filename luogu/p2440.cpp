#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
LL n,m,ans;
int arr[100010];

bool check(int mid){
    LL sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i]/mid;
    }
    return sum >= m;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int l = 0, r = 100000000;
    while(l < r){
        int mid = (l+r+1)>>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
    return 0;
}