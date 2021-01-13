#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int cnt = 0;
    int n,a;
    cin >> n;
    for(int i  = 0; i < n; i++){
        cin >> a;
        s += ('0' + a);
        if(a == 1){
            if(cnt <= 1) cnt++;
            else if(cnt == 4) cnt++;
            else if(s.size() > 1 && s[i-1] == '1') cnt = 2;
            else cnt = 1;
        }else if(a == 4){
            if(cnt == 2) cnt++;
            else if(cnt == 5){
                s[i-4] = '5';
                cnt = 0;
            }else{
                cnt = 0;
            }
        }else if(a == 5){
            if(cnt == 3) cnt++;
            else cnt = 0;
        }
        // cout << cnt << " ";
    }
    // cout << endl;
    // int pos = -1;
    // while((pos = s.find("114514")) != -1){  
    //     s[pos+1] = '5';
    // }
    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << s[i];
    }
    return 0;
}