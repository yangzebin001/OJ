/*
 * @Date: 2019-11-21 14:58:54
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-21 15:30:44
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAXN = 110;
int N,M,K;
map<int,vector<int>> oppose; 
int F[MAXN];
int _find(int x){
    return F[x] == x ? x : F[x] = _find(F[x]);
}
void _union(int a,int b){
    int c = _find(a);
    int d = _find(b);
    if(c != d){
        F[c] = d;
    }
}
bool hasre(vector<int> &a,int b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b) return 1;
    }
    return 0;
}

int main(){
    freopen("in.txt","r",stdin);
    
    int a,b,c;
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0; i <= N; i++) F[i] = i;
    for(int i = 0; i < M; i++){
        scanf("%d%d%d",&a,&b,&c);
        if(c == -1){
            oppose[a].push_back(b);
            oppose[b].push_back(a);
        }else{

            _union(a,b);
        }
    }
    for(int i = 0; i < K; i++){
        scanf("%d%d",&a,&b);
        if(!hasre(oppose[a],b)){
            if(_find(a) == _find(b))
                printf("No problem\n");
            else
                printf("OK\n"); 

        }else if(hasre(oppose[a],b)){
            if(_find(a) == _find(b))
                printf("OK but...\n");
            else
                printf("No way\n"); 
        }
    }
    return 0;
}