/*
 * @Date: 2020-01-29 21:24:33
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-29 21:46:30
 */
#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
map<char,char> h,deh;
int vis[26];
int main(){
    string secret;
    string origin;
    string needprocess;
    cin >> secret >> origin >> needprocess;
    if(secret.size() != origin.size()){
        printf("Failed\n");
        return 0;
    }
    for(int i = 0; i < secret.size(); i++){
        char c = origin[i], d = secret[i];
        vis[c-'A'] = 1;
        if(h.count(d) && h[d] != c){
            printf("Failed\n");
            return 0;
        }
        h[d] = c;
    }
    for(int i = 0; i < 26; i++){
        char c = 'A'+i;
        if(!vis[i]){
            printf("Failed\n");
            return 0;
        }
    }
    for(int i = 0; i < needprocess.size(); i++){
        cout << h[needprocess[i]];
    }
    return 0;
}