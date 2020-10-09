#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout << 14/4 << endl;
        cout << 14-(14%4) << endl;
        cout << 2 << endl;
    } else if (T == 4) {
        printf("%6.3f\n",500.0/3);
    } else if (T == 5) {
        cout << (260+220)/(12+20) << endl;
    } else if (T == 6) {
        cout << sqrt(36+81) << endl;
    } else if (T == 7) {
        cout << 110 << endl;
        cout << 90 << endl;
        cout << 0 << endl;
    } else if (T == 8) {
        cout << 10 * 3.141593 << endl;
        cout << 25 * 3.141593 << endl;
        cout << 4.0/3*3.141593*125 << endl;
    } else if (T == 9) {
        for(int i = 1; i < 10000; i++){
            int x = i;
            x /= 2;
            x--;
            x /= 2;
            x--;
            x /= 2;
            x--;
            if(x == 1){
                cout << i << endl;
                break;
            }
        }
    } else if (T == 10) {
        cout << 9 << endl;
    } else if (T == 11) {
        cout << 100.0/3 << endl;
    } else if (T == 12) {
        cout << (int)(('M'-'A')+1) << endl;
        cout << (char)('A'+ 17) << endl;
    } else if (T == 13) {
        double ans = 4.0/3*3.141593*4*4*4 + 4.0/3*3.141593*10*10*10;
        cout << (int) pow(ans,1.0/3) << endl;
    } else if (T == 14) {
        cout << 110 - (100 + sqrt(10000-4*2400)) / 2 << endl;
    }
    return 0;
}