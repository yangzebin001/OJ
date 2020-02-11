/*
 * @Date: 2020-02-07 14:53:27
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-07 15:05:22
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 100000;
string s[MAXN];
bool cmp(string s1, string s2){
    int c1 = 1+(s1[0]-'a'), c2 = 1+(s2[0]-'a');
    int len1 = s1.size(), len2 = s2.size();
    return c1*len1 < c2*len2;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        int c1 = 1+(s[i][0]-'a');
        int len1 = s[i].size();
        cnt += c1*len1*(i+1);
    }
    cout << cnt << endl;
    return 0;
}