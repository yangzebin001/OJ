/*
 * @Date: 2020-02-07 15:07:20
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-08 11:33:19
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

char M[30][30];
int n;
set<string> paths[30][2];
map<string,int> ha;
int ans;
bool check(string s){
    int i = 0, j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]) return false;
        i++,j--;
    }
    return true;
}
void dfs(int x, int y,string path){
    if(x >= n || y >= n) return;
    path += M[x][y];
    if(x+y == n-1){
        paths[x][0].insert(path);
        ha[path] = 1;
        return;
    }
    dfs(x+1,y,path);
    dfs(x,y+1,path);
}
void dfs2(int x, int y,string path){
    if(x < 0 || y < 0) return;
    path =  path + M[x][y];
    if(x+y == n-1){
        if(paths[x][0].count(path) && ha[path]){
            ans++;
            ha[path] = 0;
        }
        return;
    }
    dfs2(x-1,y,path);
    dfs2(x,y-1,path);
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",M[i]);
    }
    dfs(0,0,"");
    dfs2(n-1,n-1,"");
    
    cout << ans;
    return 0;
}