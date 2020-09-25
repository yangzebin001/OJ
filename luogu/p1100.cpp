#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << (((n&0xffff0000)>>16) | ((n&0x0000ffff) << 16)) <<endl; 
    return 0;
}