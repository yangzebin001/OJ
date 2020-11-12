#include<bits/stdc++.h>

using namespace std;
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
long long ans = 0;
int main(){
    do{

        if(arr[0] == 0) continue;
        long long sum = 0;
        for(int i = 0; i < 10; i++){
            sum = sum * 10 + arr[i];
        }
        // cout << sum << endl;
        double ss = sqrt(sum);
        if(ss == (int)ss){
            ans = max(ans, sum);
        }
    }while(next_permutation(arr,arr+10));
    cout << ans;
    return 0;
}