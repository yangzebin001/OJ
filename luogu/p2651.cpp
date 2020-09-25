#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
//a是分子，b是分母
//a1/(a2/a3/a4/...)=a1a3a4.../a2 （分母只有a2，其他都为分子）想要化为整数，只要a2能被约为1
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        b = b / gcd(a,b);
        for(int i = 3; i <= n; i++){
            cin >> a;
            b = b / gcd(a,b);
        }
        if(b == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}