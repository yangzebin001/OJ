/*
 * @Date: 2019-11-18 17:17:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-18 22:06:39
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
// 进制
// 回文串
// unsigned long long 
// 高精度
int N;
string M;
string rev(string a){
    string b = a;
    reverse(b.begin(),b.end());
    return b;
}
bool ishuiwen(string a){
    string b = a;
    a = rev(a);
    return b == a;
}
char toc(int a){
    if(a >= 0 && a <= 9) return '0'+a;
    return 'A' + (a-10);
}
int ton(char a){
    if(a >= '0' && a <= '9') return a-'0';
    return a-'A'+10;
}
string add(string a, string b){
    string ans = "";
    if(a.size() < b.size()) return add(b,a);
    int f = 0;
    for(int i = 0; i < a.size(); i++){
        int c = ton(a[i]);
        if(i < b.size()) c += ton(b[i]);
        ans += toc((c+f)%N);
        f = (c+f)/N;
    }
    if(f) ans += toc(f);
    return ans;
}
int main(){
    cin >> N >> M;
    int i = 0;
    while(i++ <= 30){
        string b = rev(M);
        M = add(b,M);
        cout << M << endl;
        if(ishuiwen(M)){
            printf("STEP=%d\n",i);
            return 0;
        }
    }
    printf("Impossible!");
    return 0;
}