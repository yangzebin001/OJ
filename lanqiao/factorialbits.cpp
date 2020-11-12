#include<bits/stdc++.h>

using namespace std;

int main(){
    double sum = 0.0;
    for(int i = 1; i <= 9999; i++){
        sum += log2(i);
    }
    cout << (int)(floor(sum)+1);
    return 0;
}