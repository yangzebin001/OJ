/*
 * @Date: 2019-12-15 16:37:51
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-16 09:49:13
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 400;
bool vis[MAXN];
int N;
string s;
int check(int a,int b){
    memset(vis,0,sizeof(vis));
    int c = 0,d = 0;
    char C = s[a];
    char D = s[b];
    while((s[a] == C || s[a] == 'w') && !vis[a]){
        vis[a] = true;
        a = (a+N-1)%N;
        c++;
    }
    while((s[b] == D || s[b] == 'w') && !vis[b]){
        vis[b] = true;
        b = (b+1)%N;
        d++;
    }
    return c+d;
}

int main(){
    cin >> N;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans,check(i,(i+1)%N));
        //如果是白珠
        if(s[i] == 'w'){
            //把它当做红珠
            s[i] = 'r';
            ans = max(ans,check(i,(i+1)%N));
            //把它当做蓝珠
            s[i] = 'b';
            ans = max(ans,check(i,(i+1)%N));
            s[i] = 'w';
        }
        if(s[(i+1)%N] == 'w'){
            s[(i+1)%N] = 'r';
            ans = max(ans,check(i,(i+1)%N));
            s[(i+1)%N] = 'b';
            ans = max(ans,check(i,(i+1)%N));
            s[(i+1)%N] = 'w';
        }
    }
    printf("%d",ans);
    return 0;
}