#include<bits/stdc++.h>

using namespace std;
string s;
set<string> ha;
int main(){
    s = "0100110001010001";
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            ha.insert(s.substr(i,j-i+1));
        }
    }
    cout << ha.size();
    return 0;
}