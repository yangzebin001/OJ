#include<bits/stdc++.h>

using namespace std;
int arr[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int main(){
    do{
        long long asum = 0,asquare = 0,acube = 0;
        long long bsum = 0,bsquare = 0,bcube = 0;
        for(int i = 0; i < 8; i++){
            asum += arr[i];
            asquare += arr[i]*arr[i];
            acube += arr[i]*arr[i]*arr[i];
        }
        for(int i = 8; i < 16; i++){
            bsum += arr[i];
            bsquare += arr[i]*arr[i];
            bcube += arr[i]*arr[i]*arr[i];
        }
        if(asum == bsum && asquare == bsquare && acube == bcube){
            for(int i = 0; i < 16; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }while(next_permutation(arr,arr+16));
    return 0;
}