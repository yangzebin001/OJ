/*
 * @Date: 2019-11-14 21:43:07
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-14 22:14:40
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string M[25] = {"","one", "two", "three", "four", "five",
 "six", "seven", "eight", "nine", "ten", 
 "eleven", "twelve", "thirteen", "fourteen", "fifteen",
 "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
vector<string> V;

string tos(int t){
    string ans = "";
    char c;
    if(t>9){
        c = '0'+t/10;
        ans += c;
        c = '0' + t%10;
        ans += c;
    }else{
        c = '0';
        ans += c;
        c = '0' + t%10;
        ans += c;
    }
    return ans;
} 
int main(){
    string a;
    getline(cin,a);
    for(int i = 0; i < a.size() && a[i] != '.'; i++){
        for(int j = 1; j <= 20; j++){
            string c = M[j];
            if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
                int t = (j*j)%100;
                V.push_back(tos(t));
                // cout << V.back()<<endl;
            }
        }
        string c = " a ";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (1*1)%100;
            V.push_back(tos(t));
        }
        c = "another";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (1*1)%100;
            V.push_back(tos(t));
        }
        c = "both";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (2*2)%100;
            V.push_back(tos(t));
        }
        c = "first";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (1*1)%100;
            V.push_back(tos(t));
        }
        c = "second";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (2*2)%100;
            V.push_back(tos(t));
        }
        c = "third";
        if(i+1 >= c.size() && a.substr(i-c.size()+1,c.size()) == c){
            int t = (3*3)%100;
            V.push_back(tos(t));
        }
    }
    sort(V.begin(),V.end());
    string ans = "";
    for(int i = 0; i < V.size(); i++){
        ans += V[i];
    }
    int i = 0;
    while(i < ans.size() && ans[i] =='0') i++;
    if(i == ans.size()){
        cout << "0" << endl;
    }else{
        cout << ans.substr(i);
    }
    return 0;
}