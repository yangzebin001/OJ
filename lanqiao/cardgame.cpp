/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-13 21:12:16 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-13 21:27:28
 */
#include<bits/stdc++.h>

using namespace std;
string s1, s2;
string q;
set<string> vis;
int inq[15];
int getidx(char a){
    if(a == 'A') return 1;
    if(a == 'X') return 10;
    if(a == 'J') return 11;
    if(a == 'Q') return 12;
    if(a == 'K') return 13;
    return a-'0';
}
void push(char a){
    q += a;
    inq[getidx(a)]++;
}
char pop(){
    char c = q[q.size()-1];
    q = q.substr(0,q.size()-1);
    inq[getidx(c)]--;
    return c;
}
int main(){
    while(cin >> s1 >> s2){
        memset(inq, 0, sizeof(inq));
        int ret = 0;
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s2.size(); j++){
                if(s1[i] == s2[j]){
                    ret = 1;
                    break;
                }
            }
        }
        if(!ret){
            cout << -1 << endl;
            continue;
        }
        q = "";
        int f = 0;
        while(s1.size() && s2.size()){
            if(f == 0){

                char c = s1[0];
                // cout << s1 << endl;
                push(c);
                
                s1 = s1.substr(1,s1.size()-1);
                if(inq[getidx(c)] > 1){
                    char t; 
                    do{
                        t = pop();
                        s1 += t;
                    }while(inq[getidx(c)] > 0);
                    continue;
                }
            }else{
                char c = s2[0];
                push(c);
                s2 = s2.substr(1,s2.size()-1);
                if(inq[getidx(c)] > 1){
                    char t; 
                    do{
                        t = pop();
                        s2 += t;
                    }while(inq[getidx(c)] > 0);
                    continue;
                }
            }
            f = !f;
        }
        if(s1.size()) cout << s1 << endl;
        else cout << s2 << endl;
    }
    return 0;
}