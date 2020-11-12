#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "vxvxvxvxvxvxvvx";
    long long c = 777;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'v'){
            c *= 2;
        }else{
            c -=555;
        }
    }
    cout << c;
    return 0;
}