#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,string> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a,b,c;
        cin >> a>> b >> c;
        if(a == "N"){

            if(m.count(b)){
                cout << "ERROR: Exist" <<endl;
            }else{
                m[b] = c;
                cout << "New: OK" << endl;
            }
        }else{
            
            if(!m.count(b)){
                cout << "ERROR: Not Exist" << endl;
            }else if(m[b] != c){
                cout <<"ERROR: Wrong PW" << endl;
            }else{
                cout << "Login: OK" << endl;
            }
        }
    }
    return 0;
}