#include<iostream>
#include<vector>
#include<string>
using namespace std;

void dfs(int i,string s,vector<string> ans){
    if(i == s.size()){
        for(int j = 0; j < ans.size(); j++){
            cout << ans[j] <<" ";
        }
        cout << endl;
        return;
    }
    string a;
    for(int j = i; j < s.size(); j++){
        a+=s[j];
        ans.push_back(a);
        dfs(j+1,s,ans);
        ans.pop_back();
    }

}

int main(){
    string s;
    cin >> s;
    vector<string> ans;
    dfs(0,s,ans);
    return 0;
}