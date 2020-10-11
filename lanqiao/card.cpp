/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 14:38:16 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2020-10-10 14:38:16 
 */
#include<bits/stdc++.h>

using namespace std;
int ans = 0;
void dfs(int i, int j){
    if(i > 13) return;
    if(j > 13) return;
    if(j == 13){
        ans++;
        return;
    }
    dfs(i+1,j); //不选当前第j种牌
    dfs(i+1,j+1); //选一张当前第j种牌
    dfs(i+1,j+2); //选二张当前第j种牌
    dfs(i+1,j+3); //选三张当前第j种牌
    dfs(i+1,j+4); //选四张当前第j种牌
}

int main(){
    dfs(0,0);
    printf("%d",ans);
    return 0;
}