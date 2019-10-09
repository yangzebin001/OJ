/*
 * @Date: 2019-09-09 19:52:32
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-09 21:12:50
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 150;

int caldir(char c){
    if(c == 'N') return 0;
    if(c == 'E') return 1;
    if(c == 'S') return 2;
    if(c == 'W') return 3;
}

struct Per{
    int dir;
    int x,y;
}P[MAXN];

int MAP[MAXN][MAXN];
int flag = 0;
int n,m;

bool judge(int ri){
    if(P[ri].x <= 0 || P[ri].x > n || P[ri].y <= 0 || P[ri].y > m){
        flag = 1;
        printf("Robot %d crashes into the wall\n",ri);
        return true;
    } else if(MAP[P[ri].x][P[ri].y] != 0){
        flag = 1;
        printf("Robot %d crashes into robot %d\n",ri,MAP[P[ri].x][P[ri].y]);
        return true;
    }
    return false;
}

void doaction(int ri, char ac, int repeat){
    if(ac == 'L'){
        P[ri].dir -= repeat;
        while(P[ri].dir < 0) P[ri].dir += 4;
    }else if(ac == 'R'){
        P[ri].dir += repeat;
        while(P[ri].dir >= 4) P[ri].dir -= 4;
    }else{
        
        while(repeat){
            MAP[P[ri].x][P[ri].y] = 0;
            if(P[ri].dir == 0) P[ri].x--;
            else if(P[ri].dir == 1) P[ri].y++;
            else if(P[ri].dir == 2) P[ri].x++;
            else if(P[ri].dir == 3) P[ri].y--;
                
            if(judge(ri)) return;
            MAP[P[ri].x][P[ri].y] = ri;
            repeat--;
        }
    }
}



int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        memset(MAP,0,sizeof(MAP));
        flag = 0;
        cin >> m >> n;
        int rcnt,w;
        cin >> rcnt >> w;
        for(int i = 1; i <= rcnt; i++){
            char c;
            cin >> P[i].y >> P[i].x >> c;
            P[i].x = n+1-P[i].x;
            MAP[P[i].x][P[i].y] = i;
            P[i].dir = caldir(c);
        }
        int ri,repeat;
        char ac;
        for(int i = 0; i < w; i++){
            cin >> ri >> ac >> repeat;
            if(flag) continue;
            doaction(ri,ac,repeat);
        }
        if(!flag) printf("OK\n");
    }
    return 0;
}