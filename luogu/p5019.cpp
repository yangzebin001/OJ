#include<iostream>
#include<algorithm>

using namespace std;
int n, ans;
int arr[100010];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++){
        ans += arr[i] - arr[i-1] > 0 ? arr[i] - arr[i-1] : 0;
    }
    cout << ans + arr[0];
    return 0;
}

/*
#include<iostream>
#include<algorithm>

using namespace std;
int n;
int arr[100010];
int dfs(int l, int r){
    if(l > r) return 0;
    int minx = arr[l];
    int idx = l;
    for(int i = l; i <= r; i++){
        if(arr[i] < minx){
            minx = min(minx, arr[i]);
            idx = i;
        }
    }
    for(int i = l; i <= r; i++){
        arr[i] -= minx;
    }
    return minx + dfs(l, idx-1) + dfs(idx+1, r);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << dfs(0,n-1);
    return 0;
}
 * 
 */
