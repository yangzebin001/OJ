#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int vis[10];

void get(int x){
    while(x){
        vis[x%10] = 1;
        x/=10;
    }
}

int main(){
    int x = 1;
    while(1){
        memset(vis,0,sizeof(vis));
        get(x*x);
        get(x*x*x);
        int f = 0;
        for(int i = 0; i < 10; i++){
            if(vis[i] == 0) f = 1;
        }
        if(f == 0) {
            cout << x << endl;
            break;
        }
        x++;
    }
    return 0;
}