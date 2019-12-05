/*
 * @Date: 2019-11-21 15:42:47
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-21 15:51:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int MAXN = 1e5+10;
struct s{
    string ID,name;
    int score;
}S[MAXN];

bool cmp1(s &a, s &b){
    return a.ID < b.ID;
}
bool cmp2(s &a, s &b){
    if(a.name == b.name)
        return a.ID < b.ID;
    return a.name < b.name;
}
bool cmp3(s &a, s &b){
    if(a.score == b.score)
        return a.ID < b.ID;
    return a.score < b.score;
}
int N,C;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&C);
    for(int i= 0; i < N; i++){
        cin >> S[i].ID >> S[i].name >> S[i].score;
    }
    if(C == 1){
        sort(S,S+N,cmp1);
    }else if(C == 2){
        sort(S,S+N,cmp2);
    }else{
        sort(S,S+N,cmp3);
    }
    for(int i = 0; i < N; i++){
        cout << S[i].ID <<" "<< S[i].name <<" "<< S[i].score << endl;
    }
    return 0;
}