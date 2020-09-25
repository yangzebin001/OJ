#include<iostream>

using namespace std;

long long  gcd(long long  a, long long  b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    long long a,b,c;  //int会爆 ⊙﹏⊙|||
    cin >> a >> b >> c;
    long long  lcm = a*b /gcd(a,b);
    lcm = lcm*c/gcd(lcm,c);
    cout << lcm << endl;
    return 0;
}