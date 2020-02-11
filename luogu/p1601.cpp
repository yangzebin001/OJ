/*
 * @Date: 2020-02-05 13:07:13
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-05 13:14:54
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;
string A,B,C;
string add(string A, string B){
    if(B.size() < A.size()) return add(B,A);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int t = 0,i;
    string C;
    for(i = 0; i < A.size(); i++){
        t = t+(A[i]-'0') + (B[i]-'0');
        C += '0' + (t%10);
        t /=10;
    }
    while(i < B.size()){
        t = t+(B[i]-'0');
        C += '0' + (t%10);
        t /=10;
        i++;
    }
    if(t) C += '1';
    return C;
}
int main(){
    cin >> A >> B;
    C = add(A,B);
    reverse(C.begin(),C.end());
    cout << C;
    return 0;
}