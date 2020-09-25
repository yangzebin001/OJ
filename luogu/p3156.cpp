#include<iostream>
#include<algorithm>

using namespace std;
int arr[2000100];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // sort(arr, arr+n);
    for(int i = 0; i < m; i++){
        cin >> n;
        cout << arr[n-1] << endl;
    }
    return 0;
}

// 1 2 4 5 8 9 11 14 17 60
