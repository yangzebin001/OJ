/*
 * @Date: 2020-02-07 15:46:22
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-07 16:04:22
 */
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int main(){
    char c;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            c = s[i];
            break;
        }
    }
    string left = s.substr(0,s.find('='));
    string right = s.substr(s.find('=')+1);
    double lefttotal = 0,righttotal = 0;
    int cur = 0;
    int ispos = 1;
    double leftxishu = 0,rightxishu = 0;
    for(int i = 0; i < left.size();){
        if(left[i] == '-'){
            ispos = -1;
            i++;
        }else if(left[i] == '+'){
            ispos = 1;
            i++;
        }
        while(i < left.size() && left[i]>= '0' && left[i] <= '9'){
            cur = cur*10+(left[i]-'0');
            i++;
        }
        cur = ispos*cur;
        if(i < left.size() && left[i] == c){
            leftxishu += cur;
            i++;
        }else{
            lefttotal += cur;
        }
        cur = 0;
        ispos = 1;
    }
    cur = 0;
    for(int i = 0; i < right.size();){
        if(right[i] == '-'){
            ispos = -1;
            i++;
        }else if(right[i] == '+'){
            ispos = 1;
            i++;
        }
        while(i < right.size() && right[i]>= '0' && right[i] <= '9'){
            cur = cur*10+(right[i]-'0');
            i++;
        }
        cur = ispos*cur;
        if(i < right.size() && right[i] == c){
            rightxishu += cur;
            i++;
        }else{
            righttotal += cur;
        }
        cur = 0;
        ispos = 1;
    }
    // cout << lefttotal << " " << leftxishu << " " << righttotal << " " << rightxishu << " " << endl;
    printf("%c=%.3f",c,(righttotal-lefttotal)/(leftxishu-rightxishu));
    return 0;
}