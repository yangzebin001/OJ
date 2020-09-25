#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstdio>
using namespace std;

int n;
int s[15], k[15];
int ans = INT_MAX;
vector<int> arr;
void dfs(int now){
    if(now == n){
        int cur_s = 1, cur_k = 0;
        if(arr.size() == 0) return;
        for(int i = 0; i < arr.size(); i++){
            cur_s *= s[arr[i]];
            cur_k += k[arr[i]];
        }
        ans = min(ans, abs(cur_k-cur_s));
        return;
    }
    dfs(now+1);
    arr.push_back(now);
    dfs(now+1);
    arr.pop_back();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> k[i];
    }
    dfs(0);
    printf("%d\n", ans);
    return 0;
}