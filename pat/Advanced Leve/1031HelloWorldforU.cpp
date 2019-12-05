#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 90;
char M[MAXN][MAXN];
int main(){
    int k = 0,N = 0,n2 = 0;
    string s;
    cin >> s;
    N = s.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            M[i][j] = ' ';
        }   
    }
    // 2*k+n2 = N+2;
    for(int i = 1; i <= N/2; i++){
        int q = (N+2-i)/2;
        if(q <= i) k = max(k,q);
    }
    n2 = N+2-2*k;
    int c = 0;
    // cout << k << " " << n2<< endl;
    for(int i = 0; i < k-1; i++) M[i][0] = s[c++];
    for(int i = 0; i < n2; i++) M[k-1][i] = s[c++];
    for(int i = k-2; i >= 0; i--) M[i][n2-1] = s[c++];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n2; j++) printf("%c",M[i][j]);
        printf("\n");
    }
    return 0;
}