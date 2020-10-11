/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 15:16:17 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-10 15:27:35
 */
#include<bits/stdc++.h>

using namespace std;

int a[10];
int grid[3][4];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, -1, -1, 0, 1, 1};
bool check(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx >= 0 && nx < 3 && ny >= 0 && ny < 4){
                    if(abs(grid[i][j]-grid[nx][ny]) == 1) return false;
                }
            }
        }
    }
    return true;
}


int main(){
    int ans = 0;
    grid[0][0] = -13;
    grid[2][3] = -32;
    for(int i = 0; i < 10; i++) a[i] = i+1;
    do{
        for(int j = 1; j <= 10; j++){
            grid[j/4][j%4] = a[j-1];
        }
        if(check()){ 
            // for(int i = 0; i < 3; i++){
            // for(int j = 0; j < 4; j++){
            //     cout << grid[i][j] << " ";
            // } cout << endl;
            // }
            ans++;}
    }while(next_permutation(a,a+10));
    cout << ans;
    return 0;
}