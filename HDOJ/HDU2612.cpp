#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

struct node{
    int x,y,step;
};
node temp;

const int INF = 0x3f3f3f3f;
const int MAXN = 250;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char m[MAXN][MAXN];
int vis[MAXN][MAXN];
int N,M;
int yx,yy,mx,my;
int sum1[MAXN][MAXN],sum2[MAXN][MAXN];
int sum;
int ans = INF;

void bfs(int a,int b,int f){
    memset(vis,0,sizeof(vis));
    queue<node> q;
    temp.x = a; temp.y = b; temp.step = 0;
    q.push(temp);
    vis[a][b] = 1;
    while(q.size()){
        temp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + temp.x;
            int ny = dy[i] + temp.y;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && m[nx][ny] != '#'){
                vis[nx][ny] = 1;
                node now = temp;
                now.x = nx; now.y = ny; now.step = temp.step+1;
                q.push(now);
                if(f) sum1[nx][ny] = temp.step+1;
                else sum2[nx][ny] = temp.step+1;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)){
        sum = 0;
        ans = INF;
        for(int i = 0; i < N; i++){
            scanf("%s",m[i]);
            for(int j = 0; j < M; j++){
                if(m[i][j] == 'Y'){
                    yx = i; yy = j;
                }else if(m[i][j] == 'M'){
                    mx = i; my = j;
                }else if(m[i][j] == '@'){
                    sum++;
                }
            }
        }
        bfs(yx,yy,1);
        bfs(mx,my,0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(m[i][j] == '@'){                
                    ans = min(ans,sum1[i][j]+sum2[i][j]);
                }
            }
        }
        printf("%d\n",ans*11);
    }
    return 0;
}