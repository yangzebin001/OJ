#include<iostream>
#include<vector>
using namespace std;

vector<int> add(vector<int> a, vector<int> b){
    if(a.size() < b.size()) return add(b,a);
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++){
        t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t%10);
        t /= 10;
    }
    if(t) c.push_back(t);
    return c;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> b(1,0);
    vector<int> a(1,1);
    for(int i = 2; i < m-n+2; i++){
        vector<int> c = add(a,b);
        b = a;
        a = c;
    }
    for(int i = a.size()-1; i >= 0; i--){
        cout << a[i];
    }
    return 0;
}