#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

stack<string> stks;
stack<int> stkn;
int main(){
    stks.push("");
    stkn.push(1);
    string s, tmp;
    cin >> s;
    int i = 0;
    // while(s[i] >= '0' && s[i] <= '9'){
    //     cout << s[i];
    //     i++;
    // }
    for(; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int num = 0;
            while(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] -'0');
                i++;
            }
            i--;
            stkn.push(num);
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            stks.top() += s[i];
        }else if(s[i] == ']'){
            string c = stks.top(); stks.pop();
            int num = stkn.top(); stkn.pop();
            string cc;
            while(num--){
                cc += c;
            }
            stks.top() += cc;
        }else if(s[i] == '['){
            stks.push("");
        }
    }
    cout << stks.top();
    return 0;
}