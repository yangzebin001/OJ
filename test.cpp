/*
 * @Date: 2019-08-19 11:49:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-08 21:37:17
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool del(string a, string b){
    int ai = 0, bi = 0, t = 0;
    while(ai < a.size()){
        if(a[ai] == b[bi]) ai++,bi++;
        else{
            ai++;
            t++;
            if(t > 1) break;
        }
    }
    return t < 2;
}

int main(){
    string a = "mrec";
    string b = "mre";
    cout << del(a,b);
    return 0;
}