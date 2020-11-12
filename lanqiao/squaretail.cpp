#include<bits/stdc++.h>

using namespace std;
set<int> vis;
int main(){
    for(int i = 1; i <= 100; i++){
        vis.insert(i*i%100);
    }
    cout << vis.size();
    return 0;
}