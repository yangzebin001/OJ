#include<bits/stdc++.h>

using namespace std;
int cnt[2000010];
int minn = INT_MAX;
int main(){
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int temp = i * i + j * j;
            cnt[temp]++;
            if (cnt[temp] > 11)
                minn = min(minn, temp);
        }
    }
    cout << minn << endl;
    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <cstring>
// #include <cmath>

// using namespace std;

// int num[2000000], minn = 10000000;

// int main() {
//     memset(num, 0, sizeof(num));
//     for (int i = 1; i < 1000; i++) {
//         for (int j = i; j < 1000; j++) {
//             int temp = i * i + j * j;
//             num[temp]++;
//             if (num[temp] > 11)
//                 minn = min(minn, temp);
//         }
//     }
//     cout << minn << endl;
//     for (int i = 1; minn > 2 * i * i; i++) {
//         int temp = (int) sqrt(minn - i * i);
//         if (temp * temp == minn - i * i) {
//             cout << temp << '*' << temp << '+' << i << '*' << i << '=' << minn << endl;
//         }
//     }
//     return 0;
// }