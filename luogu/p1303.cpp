/*
 * @Date: 2020-02-05 13:32:03
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-05 13:58:09
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string A,B,C;
vector<string> res;
int maxlen = 0;
void mul(string A, int b, int zerocunt){
    int t = 0;
    string C;
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()) t += (A[i]-'0')*b;
        C += ('0'+(t%10));
        t /= 10;
    }
    for(int i = 0; i < zerocunt; i++){
        C = '0' + C;
    }
    maxlen = max(maxlen,(int)C.size());
    res.push_back(C);
}
string add(){
    string C;
    int t = 0;
    for(int j = 0; j < maxlen || t; j++){
        for(int i = 0; i < res.size(); i++){
            if(j < res[i].size()){
                t += (res[i][j] - '0');
            }
        }
        C += ('0'+(t%10));
        t /= 10;
    }
    while(C.size() > 1 && C.back() == '0') C.pop_back();
    reverse(C.begin(),C.end());
    return C;
}
int main(){
    cin >> A >> B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i = 0; i < A.size(); i++){
        mul(B,A[i]-'0',i);
    }
    C = add();
    cout << C;
    return 0;
}