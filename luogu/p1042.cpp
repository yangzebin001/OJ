/*
 * @Date: 2020-01-19 21:04:25
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-19 21:39:49
 */
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN = 100010;
int win11[MAXN][2],win21[MAXN][2];
int cnt11A,cnt11B,cnt21A,cnt21B;
int t1 = 0, t2 = 0;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char c;
    int num11 = 0,num21 = 0;
    while(scanf("%c",&c) && c != 'E'){
        if(c == 'W'){
            cnt11A++;
            cnt21A++;
        }else if(c == 'L'){
            cnt11B++;
            cnt21B++;
        }
        if((cnt11A >= 11  || cnt11B >= 11) && abs(cnt11A-cnt11B) >=2){
            win11[t1][0] = cnt11A;
            win11[t1][1] = cnt11B;
            cnt11A = 0;
            cnt11B = 0;
            t1++;
            num11 = 0;
        }
        if((cnt21A >= 21  || cnt21B >= 21) && abs(cnt21A-cnt21B) >=2){
            win21[t2][0] = cnt21A;
            win21[t2][1] = cnt21B;
            cnt21A = 0;
            cnt21B = 0;
            t2++;
            num21 = 0;
        }
    }    
    if(abs(cnt11A-cnt11B) >=2 || 1){
        win11[t1][0] = cnt11A;
        win11[t1][1] = cnt11B;
        cnt11A = 0;
        cnt11B = 0;
        t1++;
    }
    if(abs(cnt21A-cnt21B) >=2 || 1){
        win21[t2][0] = cnt21A;
        win21[t2][1] = cnt21B;
        cnt21A = 0;
        cnt21B = 0;
        t2++;
    }
    for(int i = 0; i < t1; i++){
        cout << win11[i][0] <<":" << win11[i][1] << endl;
    }
    cout << endl;
    for(int i = 0; i < t2; i++){
        cout << win21[i][0] <<":" << win21[i][1] << endl;
    }
    return 0;
}