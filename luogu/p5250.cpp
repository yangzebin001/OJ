#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<climits>
using namespace std;

int main(){
    map<int,int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if(a == 1){
            if(m.count(b)){
                cout << "Already Exist" << endl;
            }else{
                m[b] = 1;
            }
        }else{
            if(m.empty()) cout << "Empty" << endl;
            else if(m.count(b)){
                cout << b << endl;
                m.erase(b);
            }else{
                m[b] = 1;
                auto it = m.find(b);
                auto it2 = it;
                it++;
                if(it2 == m.begin()){
                    cout << it->first << endl;
                    m.erase(it);
                }else if(it == m.end()){
                    cout << (--it2)->first << endl;
                    m.erase(it2);
                }else if(b-(--it2)->first > it->first - b) {
                    cout << it->first << endl;
                    m.erase(it);
                }else{
                    cout << it2->first << endl;
                    m.erase(it2);
                }
                m.erase(b);
            }
        }
    }
    return 0;
}