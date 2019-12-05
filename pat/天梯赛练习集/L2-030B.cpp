/*
 * @Date: 2019-11-18 14:41:55
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-18 17:01:10
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<string,string> F;
map<string,int> pos;
map<string,bool> sex;
int N,M;
bool hascommon(string a, string b){
    int i = 1,j;
    for(string A = a;A.size(); i++,A = F[A]){
        j = 1;
        for(string B = b; B.size(); j++,B = F[B]){
            if(i >= 5 && j >= 5) return 1;
            if(A == B && (i < 5 || j < 5)) return 0;
        }
    }
    return 1;
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d",&N);
    char c[50];
    string se,name;
    for(int i = 0; i < N; i++){
        cin >> name >> se;
        pos[name] = i;
        if(se.back() == 'n'){
            sex[name] = 1;
            F[name] = se.substr(0,se.size()-4);
        }else if(se.back() == 'r'){
            sex[name] = 0;
            F[name] = se.substr(0,se.size()-7);
        }else if(se.back() == 'm'){
            sex[name] = 1;
            // F[name] = se;
        }else if(se.back() == 'f'){
            sex[name] = 0;
            // F[name] = se;
        }
    }
    scanf("%d",&M);
    for(int i = 0; i < M; i++){
        string a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if(pos.find(a1) == pos.end() || pos.find(b1) == pos.end()){
            printf("NA\n");
        }else if(sex[a1] == sex[b1]){
            printf("Whatever\n");
        }else{
            if(!hascommon(a1,b1)){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }
    }
    return 0;
}