/*
 * @Date: 2019-12-14 20:34:43
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-14 21:19:23
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iterator>
#include<list>
#include<algorithm>
using namespace std;
const int MAXN = 100009;
typedef list<int>::iterator ite;
list<int> v;
ite loc[MAXN];
bool era[MAXN];
void ins(int k, int p,int c){
    if(p == 0){
        loc[c] = v.insert(loc[k], c);
    }else{
        loc[c] = v.insert(next(loc[k]), c);
        // loc[k]--;
    }
    
}
void del(int k){
    if(!era[k]){
        v.erase(loc[k]);
        era[k] = true;
    }
}
int main(){
    v.push_back(1);
    loc[1] = v.begin();
    int N,k,p,M,y;
    cin >> N;
    for(int i = 2; i <= N; i++){
        cin >> k >> p;
        ins(k,p,i);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> y;
        del(y);
    }
    list<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        if(it != v.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}