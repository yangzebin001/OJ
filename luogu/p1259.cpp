#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
string s;
string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        s += 'o';
    }
    for(int i = 0; i < n; i++){
        s += '*';
    }
    s += "--";
    int blank = 2*n;
    int mid = n-1;
    while(1){
        cout << s <<  endl;
        s[mid] = s[mid+1] = '-';
        s[blank] = 'o'; s[blank+1] = '*';
        cout << s << endl;
        s[mid] = s[mid+1] = '*';
        mid--;
        blank -= 2;
        if(blank == 6) break;
        s[blank] = s[blank+1] = '-';
    }
    string ss;
    for(int i = 0; i < n-4; i++) ss += "o*";
    for(int i = 0; i < 4; i++) cout << out[i] << ss <<endl;
    return 0;
}