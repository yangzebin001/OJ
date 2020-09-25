#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m, ans;
int arr[20100];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = n-1; i >= 0; i--){
        
        ans++;
        m -= arr[i];
        if(m <= 0){
            printf("%d\n", ans);
            return 0;
        }
    }

    return 0;
}