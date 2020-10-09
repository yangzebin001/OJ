#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n;
long long ansi, ansv = LONG_LONG_MIN;
long long arr[100010];
int main(){
    cin >> n;
    int c = 1;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0, i = 0, l = 1;
    while(cnt < n){
        cnt += c;
        cnt = min(cnt, n);
        long long now = 0;
        while(i < cnt){
            now += arr[i];
            i++;
        }
        if(now > ansv){
            ansv = now;
            ansi = l;
        }
        c <<= 1;
        l++;
    }
    cout << ansi;
    return 0;
}