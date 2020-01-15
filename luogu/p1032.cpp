/*
 * @Date: 2020-01-15 10:32:47
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-15 12:03:30
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct node{
    string str;
    int t;
};
string s,e;
string a[10][2];
map<string,string> M;
map<string,bool> vis;
int main(){
    int ai = 0;
    freopen("in.txt","r",stdin);
    cin >> s >> e;
    string b;
    M.clear();
    while(cin >> a[ai][0] >> a[ai][1]){
        ai++;
    }
    queue<string> q;
    q.push(s);
    int cnt = 0;
    while(q.size()){
        int len = q.size();
        for(int i = 0; i < len; i++){
            string t = q.front();
            q.pop();
            if(t == e){
                printf("%d",cnt);
                return 0;
            }
            for(int j = 0; j < ai; j++){
                int idx = t.find(a[j][0]);
                while(idx >= 0 && idx < t.size()){
                    string tt = t;
                    tt.replace(idx,a[j][0].size(),a[j][1]);
                    if(vis[tt]) {
                        idx = t.find(a[j][0],idx+1);
                        continue;
                    }
                    vis[tt] = true;
                    
                    q.push(tt);
                    idx = t.find(a[j][0],idx+1);
                }
            }
        }
        if(++cnt > 10)
        {
            printf("NO ANSWER!\n");
            return 0;
        }
    }
    printf("NO ANSWER!\n");
    return 0;
}