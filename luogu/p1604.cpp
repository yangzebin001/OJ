/*
 * @Date: 2020-02-10 22:16:09
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 22:32:35
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<string>
using namespace std;
int getnum(char a){
    if(isupper(a)) return 10 + (a-'A');
    return a-'0';
}
char getcc(int x){
    if(x < 10) return '0'+x;
    return 'A'+ (x-10);
}
string A,B,C;
char kk;
int k;
void add(){
    if(A.size() > B.size()) swap(A,B);
    int t = 0,i;
    for(i = 0; i < A.size(); i++){
        t += getnum(A[i]) + getnum(B[i]);
        C += getcc(t%k);
        t/=k;
    }
    while(i < B.size()){
        t += getnum(B[i]);
        C += getcc(t%k);
        t/=k;
        i++;
    }
    if(t) C += getcc(t);
    
}
int main(){
    cin >> k;
    // cout << k <<endl;
    cin >> A >> B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    add();
    reverse(C.begin(),C.end());
    cout << C;
    return 0;
}