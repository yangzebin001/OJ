#include<iostream>
#include<algorithm>
using namespace std;
int l,n,m;
int arr[60000];

bool check(int mid){
    // mid 最短跳跃的距离，
    // 在距离之内尽可能的移除石头。
    int can_remove = 0;
    int l = 0, r = 0;
    while(r < n+1){
        r++;
        //发现一个比mid 最短跳跃的距离还短的距离，说明可以移除
        if(arr[r] - arr[l] < mid) can_remove++;
        else l = r;
    }
    return can_remove <= m;
}

int main(){
    cin >> l >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    arr[n+1] = l;
    int l = 0, r = 1e9+10;
    while(l < r){
        int mid = (l+r+1) >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
    return 0;
}