#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 1000;
char maze[MAXN][MAXN];
int step[MAXN][MAXN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char cc[5] = "URLD";  //因为是从后往前看，所以方向都是反的
char ans[MAXN];
int cnt = 0;
const int N = 30,M = 50;
struct p{
    int x, y,s;
    p(){}
    p(int _x, int _y, int _s){
        x = _x;
        y = _y;
        s = _s;
    }
};

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    for(int i = 0; i < N; i++){
        scanf("%s", maze[i]);
    }
    memset(step, -1, sizeof(step));
    struct p t;
    queue<p> q;
    q.push(p(0,0,0));
    step[0][0] = 0;
    while(q.size()){
        int x = q.front().x, y = q.front().y, s = q.front().s;
        q.pop();
        step[x][y] = s;
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '1' && step[nx][ny] == -1){
                q.push(p(nx,ny,s+1));
            }
        }
    }
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << step[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x = N-1, y = M-1;
    int now = step[N-1][M-1];
    while(x != 0 || y != 0){
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && step[nx][ny] == now-1){
                ans[cnt++] = cc[i];
                x = nx, y = ny;
                now--;
                break;
            }
        }
    }

    while(cnt){
        cout << ans[cnt-1];
        cnt--;
    }
    return 0;
}