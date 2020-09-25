#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int n;
string s;
int main(){
    map<string, int> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,score;
        cin >> a;
        if(a == 1){
            cin >> s >> score;
            m[s] = score;
            cout << "OK" <<endl;
        }else if(a==2){
            cin >> s;
            if(m.find(s) == m.end()){
                cout << "Not found" <<endl;
            }else{
                cout << m[s] << endl;
            }
        }else if(a==3){
            cin >> s;
            if(m.find(s) == m.end()){
                cout << "Not found" <<endl;
            }else{
                m.erase(s);
                cout << "Deleted successfully" << endl;
            }
        }else{
            cout << m.size() << endl;
        }
    }
    return 0;
}