#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int map[510][510];
int back[510][510];
int main(){
    cin >> n >> m;
    int tot = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            map[i][j] = tot++;
        }
    }
    for(int k = 0; k < m; k++){
        int x,y,r,z;
        cin >> x >> y >> r >> z;
        if(z){ //逆时针
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    back[x+y-j][y-x+i] = map[i][j];
                }
            }
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    map[i][j] = back[i][j];
                }
            }
        }else{
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    back[x-y+j][x+y-i] = map[i][j];
                }
            }
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    map[i][j] = back[i][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

