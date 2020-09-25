#include <iostream>
#include <string>
using namespace std;

int n;

string dfs(int x, int i, string s){
    if(x == 0) return "0";
    do{
        if(x & 1) s = (i==1 ? "2" :"2("+ dfs(i,0,"")+")") + (s == "" ? "" : "+") + s;

    }while(i++, x >>= 1);
    return s;
}

int main(){
    cin >> n;
    cout << dfs(n, 0, "");
    return 0;
}
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)