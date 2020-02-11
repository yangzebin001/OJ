/*
 * @Date: 2020-01-26 18:33:16
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-26 19:05:17
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
int p1,p2,p3;
string getmid(char a, char b){
    char c = a+1;
    string ans = "";
    while(c < b){
        ans += c;
        c++;
    }
    return ans;
}
string getstar(string s){
    string ans;
    for(int i = 0; i < s.size(); i++) ans += '*';
    return ans;
}
string toup(string s){
    string ans;
    for(int i = 0; i < s.size(); i++){
        char c = 'A'+(s[i]-'a');
        ans += c;
    }
    return ans;
}
string getnnum(string s, int num){
    string ans;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < num; j++){
            ans += s[i];
        }
    }
    return ans;
}
int main(){
    cin >> p1 >>p2 >> p3;
    string s,ans;
    cin >> s;
    char curc = '#',prevc = '#';
    int type = 0;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '-'){
            if(i-1>=0 && curc != '#'){
                prevc = s[i-1];
                //是英文字母
                if((isalpha(prevc) && isalpha(curc)) && prevc < curc){
                    string t = getmid(prevc,curc);
                    if(p1 == 2){
                        t = toup(t);
                    }else if(p1 == 3){
                        t = getstar(t);
                    }
                    if(p3 == 2){
                        reverse(t.begin(),t.end());
                    }
                    t = getnnum(t,p2);
                    ans  = t + ans;
                }else if((isdigit(prevc) && isdigit(curc)) && prevc < curc){
                    string t = getmid(prevc,curc);
                    if(p1 == 3){
                        t = getstar(t);
                    }
                    if(p3 == 2){
                        reverse(t.begin(),t.end());
                    }
                    t = getnnum(t,p2);
                    ans  = t + ans;
                }else{
                    ans = '-' + ans;
                    curc = '#';
                }
            }else{
                ans = '-' + ans;
            }
        }else{
            curc = s[i];
            ans = curc + ans;
        }
    }
    cout << ans;
    return 0;
}