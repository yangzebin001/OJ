#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> ans;
int T;
int H[2000];
int now[2000];

int insert(int n){
    int cur = n%T;
    while(now[cur] != -1) cur = (cur+1)%T;
    if(H[cur] != n) return 0;
    now[cur] = n;
    return 1;
}

int main(){
    memset(now, -1, sizeof(now));
    cin >> T;
    for(int i = 0; i < T; i++){
        int a;
        cin >>a;
        H[i] = a;
        if(a >= 0) v.push_back(a);
    }
    sort(v.begin(),v.end());
    while(v.size()){
        for(int i = 0; i < v.size(); i++){
            if(insert(v[i])){
                ans.push_back(v[i]);
                v.erase(v.begin()+i);
                break;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i > 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}