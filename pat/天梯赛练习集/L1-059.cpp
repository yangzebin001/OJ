/*
 * @Date: 2019-11-10 17:12:04
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-10 17:20:28
 */
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N;
    cin >> N;
    getchar();
    while(N--){
        string a;
        getline(cin, a);
        stringstream aa(a);
        string str[100];
        int cnt = 0;
        int first = 0,second = 0;
        while(aa >> a){
            if(a.size() >= 4 && a.substr(a.size()-4,4) == "ong,"){ first = 1;}
            if(a.size() >= 4 && a.substr(a.size()-4,4) == "ong."){ second = 1;}
            str[cnt++] = a;
        }
        if(!first || !second){
            cout << "Skipped" << endl;
            continue;
        }
        for(int i = 0; i < cnt-3; i++){
            cout << str[i] << " ";
        }
        cout << "qiao ben zhong." << endl;

    }
    return 0;
}