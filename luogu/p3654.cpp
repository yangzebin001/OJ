#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
char map[110][110];
int r,c,k, ans;

bool check_row(int i, int j){
    int kk = k;
    while(kk && j < c && map[i][j] == '.'){
        kk--;
        j++;
    }
    return kk == 0;
}

bool check_column(int i, int j){
    int kk = k;
    while(kk && i < r && map[i][j] == '.'){
        kk--;
        i++;
    }
    return kk == 0;
}

int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(int i = 0; i < r; i++){
        scanf("%s",map[i]);
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == '.'){
                ans += check_column(i,j);
                // printf("%d ", ans);
                ans += check_row(i,j);
                // printf("%d ", ans);
            }
        }
    }
    if(k == 1) ans /= 2;
    printf("%d", ans);
    return 0;
}