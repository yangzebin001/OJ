#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int F[100010];
map<string,int> tonum;
map<int, string> toname;

int getf(int n){
    while(F[n] != n){
        n = F[n];
    }
    return n;
}

int main(){
    int idx = 0;
    for(int i = 0; i < 100010; i++){
        F[i] = i;
    }
    string a;
    int father;
    while(1){
        cin >> a;
        if(a == "$") break;
        if(a[0] == '#'){
            a = a.substr(1);
            if(tonum.count(a)){
                father = tonum[a];
            }else{
                father = idx;
                tonum[a] = idx;
                toname[idx] = a;
                idx++;
            }
        }else if(a[0] == '+'){
            a = a.substr(1);
            if(tonum.count(a)){
                F[tonum[a]] = father;
            }else{
                tonum[a] = idx;
                toname[idx] = a;
                F[idx] = father;
                idx++;
            }
        }else{
            a = a.substr(1);
            int t = tonum[a];
            int f = getf(t);
            cout << a << " " << toname[f] << endl;
        }
    }
    return 0;
}