#include<iostream>
#include<cstring>
using namespace std;
int connect[30][30];
int n;
int ans = 0;
int vis[30];
int w[30];
int path[30];
int arr[30];
int ans_idx = 0;
void dfs(int x, int t, int idx){
    if(t > ans){
        ans = t;
        memcpy(arr, path, sizeof(arr));
        ans_idx = idx;
    }
    
    for(int i = x+1; i <= n; i++){
        if(!vis[i] && connect[x][i]){
            vis[i] = 1;
            path[idx] = i;
            dfs(i, t+w[i], idx+1);
            vis[i] = 0;
        }
    }

}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }   
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            cin >> connect[i][j];
            connect[j][i] = connect[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        path[0] = i;
        vis[i] = 1;
        dfs(i, w[i], 1);
        vis[i] = 0;
    }
    for(int i = 0; i < ans_idx; i++){
        cout << arr[i] << " ";
    }
    cout << endl << ans << endl;
    return 0;
}