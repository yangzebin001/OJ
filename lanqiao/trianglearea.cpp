#include<bits/stdc++.h>

using namespace std;

int main(){
    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << (x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2)/2;
    return 0;
}