#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int cp = 0;
    string a;
    map<string,int> m;
    for(int i = 0; i < n; i++){
        string q,r;
        cin >> q >>r;
        m[q]++;
        m[r]++; 
    }
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if(it->second > cnt){
            cnt = it->second;
            a = it->first;
            cp = 1;
        }else if(it->second == cnt){
            cp++;
        }
    }
    // for(it = m.begin(); it != m.end(); it++){
    //     if(it->second == cnt){
    //         cp++;
    //     }
    // }
    cout << a << " " << cnt;
    if(cp != 1) cout << " " << cp;

    return 0;
}