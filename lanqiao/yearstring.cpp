/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-14 17:23:37 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-14 20:30:45
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "A";
    long long i = 1;
    while(s != "LANQIAO"){
        int t = s.size()-1;
        while(t >= 0 && s[t] == 'Z'){
            s[t] = 'A';
            t--;
        }
        if(t == -1) s = s + 'A';
        else{
            s[t]++;
        }
        i++;
        // cout << s << endl;
    }
    cout << i;
    return 0;
}