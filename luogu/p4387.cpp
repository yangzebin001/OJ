#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int a[100010],b[100010];
int q,n;
stack<int> s;
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++){
            s.push(a[i]);
            while((s.top()) == b[sum]){
                s.pop();
                sum++;
                if(s.empty()) break;
            }
        }
        if(s.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
        while(!s.empty()) s.pop();
    }
    return 0;
}