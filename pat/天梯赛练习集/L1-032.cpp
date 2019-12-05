/*
 * @Date: 2019-11-10 17:11:12
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-10 17:11:16
 */
/*
 * @Date: 2019-08-19 11:49:38
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-10 17:07:48
 */
#include<iostream>
#include<string>
using namespace std;

int main(){
    int len;
    char c;
    string a;
    cin >> len >> c;
    getchar();
    getline(cin,a);
    // cout << len << " " << c << endl;
    if(len > a.size()){
        for(int i = a.size(); i != len; i++)
            a = c + a;
    }else{
        a = a.substr(a.size()-len,len);
    }
    cout << a;
    
}