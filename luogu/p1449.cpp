/*
 * @Date: 2019-12-15 17:22:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-15 17:27:02
 */
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main(){
    long long num = 0;
    char c;
    stack<long long> s;
    while((c = getchar()) != '@'){
        if(c == '+'){
            long long b = s.top();s.pop();
            long long a = s.top();s.pop();
            s.push(a+b);
        }else if(c == '-'){
            long long b = s.top();s.pop();
            long long a = s.top();s.pop();
            s.push(a-b);
        }else if(c == '*'){
            long long b = s.top();s.pop();
            long long a = s.top();s.pop();
            s.push(a*b);
        }else if(c == '/'){
            long long b = s.top();s.pop();
            long long a = s.top();s.pop();
            s.push(a/b);
        }else if(c == '.'){
            s.push(num);
            num = 0;
        }else{
            num = num*10+(c-'0');
        }
    }
    printf("%lld",s.top());
    return 0;
}