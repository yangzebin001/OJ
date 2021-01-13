#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;

int cal1(int a, int b, int x){
    return a*x+b;
}


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> a >> b >> n;
        int f = 0;
        double maxV = INT_MIN;
        int maxVa = 0,maxVb = 0;
        for(int i = 0; i <= n; i++){
            double now = cal1(a,b,i)*1.0/(1<<i);
            if(now > maxV){
                maxV = now;
                maxVa = cal1(a,b,i);
                maxVb = 1 << i;
            }
        }
        if(maxVa < 0){
            maxVa = -maxVa;
            f = 1;
        } 
        int c = maxVa / gcd(maxVa,maxVb);
        int d = maxVb / gcd(maxVa,maxVb);

        if(f) c = -c;
        if(c == 0) cout << 0 << endl;
        else 
        if(d == 1) cout << c << endl;
        else cout << c << "/" << d << endl;
       
    }
    
    return 0;
}