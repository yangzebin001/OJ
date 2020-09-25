#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
typedef unsigned long long ULL;

int base = 1331;

ULL arr[10010];
ULL p[10010];
ULL h[10010];

int main(){
    p[0] = 1;
    int n;
    cin >> n;
    string s;
    for(int k = 0; k < n; k++){
        cin >> s;
        ULL hash = 0;
        for(int i = 1; i < s.size(); i++){
            hash = hash * base +s[i-1];
            // p[i] = p[i-1] * base;
        }
        h[k] = hash;
    }
    int ans = 1;
    sort(h,h+n);
    for(int i = 1; i < n; i++){
        if(h[i] != h[i-1]) ans++;
    }
    cout << ans;
    return 0;
}