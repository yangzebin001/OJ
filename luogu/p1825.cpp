#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
#include<cstdio>
#include<deque>
using namespace std;

int n,m, ans = INT_MAX;
char field[330][330];
int vis[330][330];
int startx, starty;
int endx, endy;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct Transfer{
    int x1 = -1,y1 = -1,x2 = -1,y2 = -1;
}transfer[26];

struct Point{
    int x, y,s;
    Point(int _x, int _y, int _s){
        x = _x;
        y = _y;
        s = _s;
    }
};

void insert(char a, int i, int j){
    if(transfer[a-'A'].x1 == -1){
        transfer[a-'A'].x1 = i;
        transfer[a-'A'].y1 = j;
    }else{
        transfer[a-'A'].x2 = i;
        transfer[a-'A'].y2 = j;
    }
}

pair<int,int> getOther(char a, int i, int j){
    if(transfer[a-'A'].x1 == i && transfer[a-'A'].y1 == j){
        return make_pair(transfer[a-'A'].x2, transfer[a-'A'].y2);
    }else{
        return make_pair(transfer[a-'A'].x1, transfer[a-'A'].y1);
    }
}
 

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%s", field[i]);
        for(int j = 0; j < m; j++){
            if(field[i][j] == '@'){
                startx = i; starty = j;
                field[i][j] = '#';
            }else if(field[i][j] == '='){
                endx = i, endy = j;
                field[i][j] = '.';
            }else if(field[i][j] >= 'A' && field[i][j] <= 'Z'){
                insert(field[i][j], i, j);
            }
        }
    }
    deque<Point> q;
    q.push_front(Point(startx, starty, 0));
    vis[startx][starty] = 1;

    while(q.size()){
        Point now = q.front(); q.pop_front();

        if(now.x == endx && now.y == endy){
            cout << now.s << endl;
            return 0;
        }

        if(field[now.x][now.y] >= 'A' && field[now.x][now.y] <= 'Z'){
            pair<int,int> other = getOther(field[now.x][now.y], now.x, now.y);
            //坑点：遇见传送点必跳，但不能跳过去立马跳回来，这样会死循环，要多向外走一步再回来。
            now.x = other.first;
            now.y = other.second;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + now.x;
            int ny = dy[i] + now.y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] != '#' && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push_back(Point(nx,ny, now.s+1));
            }
        }
    }
    
    return 0;
}