#include<iostream>
#include<queue>
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int ax,ay,bx,by;
set<string> vis; 
int toone(int x, int y){
    return x * 3 + y;
}

pair<int,int> totwo(int x){
    return make_pair(x/3, x%3);
}

pair<int,int> getspace(string s){
    int nx,ny;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            return totwo(i);
        }
    }
}

bool check(string s){
    int nx,ny, mx,my;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            nx = totwo(i).first;
            ny = totwo(i).second;
        }
        if(s[i] == 'B'){
            mx = totwo(i).first;
            my = totwo(i).second;
        }
    }
    return nx == bx && ny == by && mx == ax && my == ay;
}



int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    string c = a+b;
    for(int i = 0; i < c.size(); i++){
        if(c[i] == 'A'){
            ax = totwo(i).first;
            ay = totwo(i).second;
        }
        if(c[i] == 'B'){
            bx = totwo(i).first;
            by = totwo(i).second;
        }
    }

    queue<string> q;
    int ans = -1;
    q.push(c);
    while(q.size()){
        int len = q.size();
        ans++;
        for(int i = 0; i < len; i++){
            string now = q.front(); q.pop();
//            cout << now << endl; 
            if(check(now)){
                printf("%d", ans);
                return 0;
            }
            vis.insert(now);
            int sx = getspace(now).first, sy = getspace(now).second;
            for(int k = 0; k < 4; k++){
                int nx = dx[k] + sx;
                int ny = dy[k] + sy;
                if(nx >= 0 && nx < 2 && ny >= 0 && ny < 3){
                    string t = now;
                    swap(t[toone(sx,sy)], t[toone(nx,ny)]);
                    if(!vis.count(t)) q.push(t);
                }
            }
        }
    }
    return 0;
}