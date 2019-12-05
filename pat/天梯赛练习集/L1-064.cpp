/*
 * @Date: 2019-11-08 21:49:32
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-09 16:55:46
 */
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<sstream>
#include<vector>
using namespace std;
int N;
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    string a;
    cin >> N;
    getchar();
    while(N--){
        vector<string> str;
        getline(cin,a);
        cout << a << endl << "AI:";

        for(int i = 0; i < a.size(); i++){
            if(isalnum(a[i])){
                if(a[i] != 'I')
                    a[i] = tolower(a[i]);
            }else{ a.insert(i," "); i++; }
            if(a[i] == '?') a[i] = '!';
        }

        stringstream ss(a);
        
        while(ss >> a) {
            str.push_back(a);
        }
        //////////////
        if(!str.size()){
            cout << " " << endl;
            continue;
        }
        /////////////
        if(!isalnum(str[0][0])) cout << " ";
        for(int i = 0; i < str.size(); i++){
            if(!isalnum(str[i][0])) cout << str[i];
            else if(i+1 < str.size() && str[i] == "can" && str[i+1] == "you"){
                cout << " I can";
                i++;
            }else if(i+1 < str.size() && str[i] == "could" && str[i+1] == "you"){
                cout << " I could";
                i++;
            }else if(str[i] == "I" || str[i] == "me") cout << " you";
            else cout << " " << str[i];
            
        }
        cout << endl;
    }
    return 0;
}