/*
 * @Date: 2019-12-15 15:19:33
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-15 16:29:06
 */
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

vector<string> v;

int getcurc(string s,string c){
    int n = 0;
    for(int i = 0; i < min(s.size(), c.size()); i++){
        if(s[i] == c[i]) n++;
    }
    return n;
}

int main(){
    freopen("in.txt","r",stdin);
    string t = "";
    int i = 0,minute;
    double sum = 0;
    char c;
    while(scanf("%c",&c) && c != 'E'){
        if(c == '\n'){
            v.push_back(t);
            t = "";
        }else if(c == '<'){
            if(t.size()) t.resize(t.size()-1);
        }else{
            t += c;
        }
    }
    getchar();
    getchar();
    getchar();
    t = "";
    while(scanf("%c",&c) && c != 'E'){
        if(c == '\n'){
            if(i < v.size()) sum += getcurc(t,v[i]);
            // cout << t << endl;
            t = "";
            i++;
        }else if(c == '<'){
            if(t.size()) t.resize(t.size()-1);
        }else{
            t += c;
        }
    }
    getchar();
    getchar();
    getchar();
    scanf("%d",&minute);
    printf("%.0lf",sum/minute*60);
    return 0;
}