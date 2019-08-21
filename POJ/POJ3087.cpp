#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;

string origin;
set<string> s;

string change(string a){
    int n = a.size();
    int m = n/2;
    int i = 0,j = m;
    string ans = "";
    while(i < m){
        ans += a[j++];
        ans += a[i++]; 
    }
    return ans;
}

int main(){
    int T;
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        s.clear();
        int len;
        char a[200],b[200];
        char c[500];
        scanf("%d%s%s%s",&len,a,b,c);
        string aa(a);
        string bb(b);
        string cc(c);
        // printf("%s %s\n",aa.c_str(),bb.c_str());
        origin = aa+bb;
        // printf("%s\n",origin.c_str());
        if(origin == cc){
            printf("%d %d\n",i,0);
            continue;
        }
        int step = 0;
        string now = origin;
        while(!s.count(now)){
            if(now == cc) break;
            s.insert(now);
            step++;
            now = change(now);
        }
        if(s.count(now)){
            printf("%d -1\n",i);
        }else{
            printf("%d %d\n",i,step);
        }

    }
    return 0;
}