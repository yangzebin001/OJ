#include<iostream>
#include<string>
using namespace std;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int n,m;
char map[110][110];
int cnt[110][110];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%s", map[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '*') {
                for(int k = 0; k < 8; k++){
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        cnt[nx][ny]++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '*'){
                putchar('*');
            }else{
                printf("%d", cnt[i][j]);
            }
        }
        printf("\n");
    }

    system("pause");
    return 0;
}