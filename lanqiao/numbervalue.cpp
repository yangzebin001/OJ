#include<bits/stdc++.h>

using namespace std;
int a = 1, b = 1 ,c = 1;
int main(){
    for(int i = 4; i <= 20190324; i++){
        int d = (a+b+c)%10000;
        a = b;
        b = c;
        c = d;
    }
    cout << c << endl;
    return 0;
}