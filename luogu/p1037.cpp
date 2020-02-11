/*
 * @Date: 2020-02-10 15:43:07
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-10 16:12:54
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;
int to[10][10];
int cnt[10];
string ans = "1";
void mul(int x){
    int t = 0;
    string C = "";
    for(int i = 0; i < ans.size() || t; i++){
        if(i < ans.size()){
            t += (ans[i]-'0')*x;
        }
        C += '0'+(t%10);
        t/=10;
    }
    ans = C;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        to[a][b] = 1;
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i != j && j != k && i != k){
                    if(to[i][k] && to[k][j]){
                        to[i][j] = 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 10; i++){
        cnt[i] = 1;
        for(int j = 0; j < 10; j++){
            cnt[i] += to[i][j];
        }
    }
    for(int i = 0; i < n.size(); i++){
        int t = (n[i]-'0');
        if(cnt[t])
            mul(cnt[t]);
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}