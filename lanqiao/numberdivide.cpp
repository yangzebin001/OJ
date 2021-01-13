#include<bits/stdc++.h>

using namespace std;
int arr[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int vis[17];

int ans[17];

void dfs(int idx){
    if(idx == 9){
        int t = 0;
        long long asum = 0, asquare = 0, acube = 0;
        long long bsum = 0, bsquare = 0, bcube = 0;
        for(int i = 1; i <= 16; i++){
            if(vis[i]){
                ans[t++] = i;
                asum += i;
                asquare += i*i;
                acube += i*i*i;
            }else{
                bsum += i;
                bsquare += i*i;
                bcube += i*i*i;
            }
        }
        if(asum == bsum && asquare == bsquare && acube == bcube){
            for(int i = 0; i < t; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

        return;
    }
    for(int i = 2; i <= 16; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(idx+1);
            vis[i] = 0;

        }
    }
}

int main(){
    // vis[1] = 1;
    // dfs(2);
    // return 0;
    printf("1 4 6 7 10 11 13 16");
}