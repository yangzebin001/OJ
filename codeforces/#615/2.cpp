/*
 * @Date: 2020-01-22 23:00:40
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-22 23:18:05
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct package{
    int x,y;
    package(int a,int b):x(a),y(b){};
    package(){};
};
int cmp(package &a, package &b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
string topath(package &a, package &b){
    string ans = "";
    int n = b.x-a.x;
    for(int i = 0; i < n; i++) ans += "R";
    int m = b.y-a.y;
    for(int i = 0; i < m; i++) ans += "U";
    return ans;
}
void solve(){
    int n;
    scanf("%d",&n);
    vector<package> V;
    for(int i = 0; i < n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        V.push_back(package(x,y));
    }
    sort(V.begin(),V.end(),cmp);
    V.insert(V.begin(),package(0,0));
    for(int i = 1; i <V.size(); i++){
        if(V[i-1].x <= V[i].x && V[i-1].y <= V[i].y){
            continue;
        }else{
            printf("NO\n");
            return;
        }
    }
    string ans = "";
    for(int i = 1; i < V.size(); i++){
        ans += topath(V[i-1],V[i]);
    }
    printf("YES\n%s\n",ans.c_str());
}
int main(){
    // freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}