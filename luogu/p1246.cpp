#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main(){
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = ans * 26 + (s[i]-'a'-i+1);
    }
    cout << ans;
    return 0;
}