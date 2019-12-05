/*
 * @Date: 2019-10-27 16:49:49
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-27 17:11:19
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 2e3+10;
char S[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    int N;
    
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%s",S+i);
    }
    int a = 0, b = N-1;
    int cnt = 0;
    while(a <= b){
        bool left = false;
        //按正序和倒序 排小的选。
        for(int i = 0; a+i <= b; i++){
            if(S[a+i] < S[b-i]){
                left = true;
                break;
            }else if(S[a+i] > S[b-i]){
                left = false;
                break;
            }
            
        }
        if(left){
            putchar(S[a++]);
        }else{
            putchar(S[b--]);
        }
        cnt++;
        if(cnt == 80){
            cnt = 0;
            puts("");
        }
    }
    return 0;
}