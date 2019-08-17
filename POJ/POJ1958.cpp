#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int d[30];
int f[30];

int main(){
    d[1] = 1;
    memset(f,0x3f,sizeof f);
    f[1] = 1;
    for(int i = 2; i < 14; i++){
        //先将上面i-1个移动到B，第i个移动到C，再将i-1个从B移动到C 为 d[i-1]*2 + 1;
        d[i] = 2*d[i-1]+1;
    }
    for(int i = 2; i < 14; i++){
        for(int j = 1; j <= i; j++){
            //考虑一共有i个，从1-i中，每次选j（1<=j<=i）个移动到B（四塔问题），将剩下的i-j个从A经C移动到D（三塔问题），再将B上的j个移动到D（四塔问题），取最小值。
            f[i] = min(f[i], 2 *f[j] + d[i-j]);
        }
    }
    for(int i = 1; i < 13; i++) cout << f[i] << endl;
    return 0;
}