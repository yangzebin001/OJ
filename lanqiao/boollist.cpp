#include<bits/stdc++.h>

using namespace std;
int arr[12] = {-1,1,2,3,4,5,6,7,8,9,10,-1};
int ans;
int main(){
    do{
        int i;
        for(i = 1; i <= 10; i++){
            if(abs(arr[i-1]-arr[i]) == 1 || abs(arr[i+1]-arr[i]) == 1){
                break;
            }
        }
        if(i == 11) ans++;
    }while(next_permutation(arr+1,arr+11));
    cout << ans;
    return 0;
}