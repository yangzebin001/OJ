/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-16 11:49:57 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-16 11:49:57 
 */
#include<bits/stdc++.h>

using namespace std;
int pirate[12];
void dfs(int idx){
    if(idx == 12){
        for(int i = 0; i < 12; i++){
            cout << pirate[i] << ' ';
        }
        return;
    }
    int count = 0;
    for(int i = 0; i < 12; i++){
        if(i == idx) continue;
        if(pirate[i] % 2) return;
        pirate[i] /= 2;
        if(pirate[i] == 0) return;
        count += pirate[i];
    }
    pirate[idx] += count;
    dfs(idx+1);
}
int main(){
    for(int i = 12; i <= 50000; i+= 12){
        for(int j = 0; j < 12; j++){
            pirate[j] = i/12;
        }
            dfs(0);
    }
    return 0;
}