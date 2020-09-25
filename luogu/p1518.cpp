#include<iostream>
#include<cstdio>
#include<set>

using namespace std;
char map[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int fx, fy, cx, cy, fidx = 0, cidx = 0;

set<int> vis;
int main(){
    for(int i = 0; i < 10; i++){
        scanf("%s", map[i]);
        for(int j = 0; j < 10; j++){
            if(map[i][j] == 'F'){
                fx = i, fy = j;
            } else if(map[i][j] == 'C'){
                cx = i, cy = j;
            }
        }
    }
    int ans = 0;
    while(1) {
        //f
        int nfx = fx + dx[fidx];
        int nfy = fy + dy[fidx];
        if(nfx < 0 || nfx >= 10 || nfy < 0 || nfy >= 10 || map[nfx][nfy] == '*'){
            fidx = (fidx + 1)%4;
        }else{
            fx = nfx;
            fy = nfy;
        }

        int ncx = cx + dx[cidx];
        int ncy = cy + dy[cidx];
        if(ncx < 0 || ncx >= 10 || ncy < 0 || ncy >= 10 || map[ncx][ncy] == '*'){
            cidx = (cidx + 1)%4;
        }else{
            cx = ncx;
            cy = ncy;
        }

        ans++;

        if(cx == fx && cy == fy){
            printf("%d", ans);
            return 0;
        }
        int num = fx*100000 + fy*10000 + fidx *1000 + cx*100 + cy*10 + cidx;
        if(vis.count(num)){
            printf("%d", 0);
            return 0;
        }
        vis.insert(num);

    }
    return 0;
}