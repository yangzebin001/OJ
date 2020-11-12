#include<bits/stdc++.h>

using namespace std;
int field[100][100];
int n,m;
int vis[100][100];
int visnum[10100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool check(int c, int d, int x, int y){
    
    for(int i = c; i < x; i++){
        for(int j = d; j < y; j++){
            vis[i][j] = 1;
            if(field[i][j] != field[c][d]) return false;

        }
    }
    return true;
}
string s;
int main(){
    int t;
    cin >> t;
    while(t--){
        set<int> ha;
        memset(vis,0,sizeof(vis));
        memset(field,0,sizeof(field));
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < m; j++){
                field[i][j] = s[j]-'0';
            }
        }
        int f = 0;
        for(int i = 0; i < n; i++){
            if(f) break;
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){

                    if(ha.count(field[i][j])){
                        f = 1;
                        break;
                    }
                    ha.insert(field[i][j]);
                    int x = i+1,y = j+1;
                    while(x < n && field[x][j] == field[i][j]) x++;
                    while(y < m && field[i][y] == field[i][j]) y++;
                    if(!check(i,j,x,y)){
                        f = 1;
                        break;
                    }
                }
            }
        }
        if(f) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}