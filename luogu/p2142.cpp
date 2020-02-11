/*
 * @Date: 2020-02-05 13:16:08
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-05 13:30:56
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;
string A,B,C;

string sub(string A, string B){
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int t = 0;
    string C;
    for(int i = 0; i < A.size(); i++){
        t = (A[i]-'0') - t;
        if(i < B.size()) t -= (B[i]-'0');
        C += '0'+((t+10)%10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == '0') C.pop_back();
    reverse(C.begin(),C.end());
    return C;
}

int main(){
    cin >> A >> B;
    if(A.size() == B.size()){
        if(A>=B) C = sub(A,B);
        else C = "-" + sub(B,A);
    }else if(A.size() > B.size()){
        C = sub(A,B);
    }else{
        C = "-" + sub(B,A);
    }
    cout << C;
    return 0;
}