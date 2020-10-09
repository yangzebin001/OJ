#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n,a;
set<int> s;
set<int>::iterator it;
int main(){
    cin >> n;
    for(int i = 1; i <= 2*1000000; i++) s.insert(i);
    for(int i = 1; i <= n; i++){
        if(i > 1) cout << " ";
        cin >> a;
        if(s.count(a)){
            cout << a;
            s.erase(a);
        }else{
            it = s.lower_bound(a);
            cout << *it;
            s.erase(it);
        }
    }
    return 0;
}