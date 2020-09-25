#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;

int n;
int arr[1024];

pair<int,int> dfs(int l, int r){
    if(l + 1 == r){
        if(arr[l] > arr[r]) 
            return make_pair(l, r);
        else 
            return make_pair(r, l);
    }
    int mid = l + r >> 1;
    pair<int, int> a = dfs(l, mid);
    pair<int, int> b = dfs(mid+1, r);
    if(arr[a.first] > arr[b.first]){
        return make_pair(a.first, b.first);
    }
    return make_pair(b.first, a.first);
}
int main(){
    cin >> n;
    for(int i = 0 ; i < (1<<n); i++) cin >> arr[i];
    cout << dfs(0,(1<<n)-1).second+1 << endl;
    return 0;
}
