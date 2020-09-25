#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000010];
int n,m, a;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int j = 0; j < m; j++){
        cin >> a;
        int l = 0, r = n-1;
        while(l < r){
            int mid = l+r>>1;
            if(arr[mid] >= a) r = mid;
            else l = mid+1;
        }
        if(arr[l] == a) cout << l+1 << " ";
        else cout << -1 << " ";
    }
    return 0;
}