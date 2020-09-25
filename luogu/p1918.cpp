#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n;

int main(){
    cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m[a] = i+1;
    }   
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int c;
        cin >> c;
        cout << m[c] << endl;
    }
    return 0;
}