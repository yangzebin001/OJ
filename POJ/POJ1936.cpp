/*
 * @Date: 2019-09-09 15:53:22
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-09 15:58:06
 */
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
    string a,b;
    freopen("in.txt","r",stdin);
    while(cin >> a >> b){
        int ai = 0;
        for(int i = 0; i < b.size(); i++){
            if(b[i] == a[ai]) ai++;
        }
        if(ai == a.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}