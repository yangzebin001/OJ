/*
 * @Date: 2019-12-02 19:14:44
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-02 19:38:16
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
int t = -1,N,M;
vector<int> v;

int main(){
    scanf("%d%d",&N,&M); 
    for(int i = 0; i < N; i++){
        v.push_back(i+1);
    }  
    int q = 0;
    while(q < N){
        int c = 0;
        while(c < M){
            t = (t+1)%N;
            while(v[t] == -1){
                t = (t+1)%N;
            }
            c++;
        }
        printf("%d ",v[t]);
        v[t] = -1;
        q++;
    }
    return 0;
}