/*
 * @Date: 2019-09-17 10:47:35
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-17 11:24:20
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int MAXN = 1000000+10;
const int INF = 0x3f3f3f3f;
int N;
map<int,int> s;
int arr[MAXN];
int cnt[MAXN];
int ans = INF;
int step = 0;

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
        if(s.count(arr[i]) == 0) s[arr[i]] = step++;
    }    
    int l = 0,r = 0,num = 0;
    while(1){
        //先全覆盖
        while(r < N && num < step){
            if(cnt[s[arr[r++]]]++ == 0) num++;
        }
        //到最后了
        if(num < step) break;
        ans = min(ans, r-l);
        //一个一个减。
        if(--cnt[s[arr[l++]]] == 0) num--;
    }
    printf("%d",ans);
    return 0;
}