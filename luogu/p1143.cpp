#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
string s;

int getdigit(char a){
    if(a >= '0' && a <='9') return a-'0';
    return (a-'A') + 10;
}

char getch(int a){
    if(a < 10) return '0'+a;
    return 'A'+(a-10);
}

int main(){
    int num = 0, x = 1;
    cin >> n >> s >> m;
    string ans = "";
    for(int i = s.size()-1; i >= 0; i--){
        num += getdigit(s[i])*x;
        x*=n;
    }
    while(num){
        ans = getch(num%m) + ans;
        num /= m;
    }
    cout << ans;
    return 0;
}