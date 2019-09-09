/*
 * @Date: 2019-08-31 21:41:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-31 22:05:43
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int A[10],B[10];
vector<int> a;
vector<int> b;

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size()) return add(B,A);
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t += A[i];
        if(i < B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    return C;
}

int main(){
    char c;
    int flag = 0;
    vector<int> a,b,d;
    while((c = getchar()) && c >= '0' && c <= '9') a.push_back(c-'0');
    for(int i = 0; i < a.size(); i++){
        A[a[i]]++;
    }
    reverse(a.begin(),a.end());
    b = a;
    d = add(a,b);
    reverse(d.begin(),a.end());
    for(int i = 0; i < d.size(); i++){
        B[d[i]]++;
    }
    for(int i = 0; i < 10; i++){
        if(A[i] != B[i]){
            flag = 1; break;
        }
    }
    if(flag == 1)printf("No\n");
    else printf("Yes\n");
    for(int i = 0; i < d.size(); i++){
        printf("%d",d[i]);
    }
    return 0;
}