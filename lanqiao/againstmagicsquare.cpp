#include<bits/stdc++.h>

using namespace std;
int arr[9] = {1,2,3,4,5,6,7,8,9};
int sum[9];
set<string> vis;
bool check(){
    sum[0] = arr[0]+arr[1]+arr[2];
    sum[1] = arr[3]+arr[4]+arr[5];
    sum[2] = arr[6]+arr[7]+arr[8];
    sum[3] = arr[0]+arr[3]+arr[6];
    sum[4] = arr[1]+arr[4]+arr[7];
    sum[5] = arr[2]+arr[5]+arr[8];
    sum[6] = arr[0]+arr[4]+arr[8];
    sum[7] = arr[2]+arr[4]+arr[6];
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            if(sum[i] == sum[j]) return false;
        }
    }
    return true;
}

string gets(){
    string s = "";
    s += '0'+arr[0];
    s += '0'+arr[1];
    s += '0'+arr[2];
    s += '0'+arr[5];
    s += '0'+arr[8];
    s += '0'+arr[7];
    s += '0'+arr[6];
    s += '0'+arr[3];
    return s;
}

int main(){
    // do{
    //     string c = gets();
    //     if(check() && !vis.count(c)){
    //         vis.insert(c);
    //     }

    // }while(next_permutation(arr,arr+9));
    // cout << vis.size()/8;
    cout << 3120 << endl;
    return 0;
}