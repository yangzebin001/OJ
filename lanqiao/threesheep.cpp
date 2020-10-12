#include<bits/stdc++.h>

using namespace std;
int vis[10];
int main(){
    for(int a = 1; a <= 9; a++)
    for(int b = 0; b <= 9; b++)
    for(int c = 0; c <= 9; c++)
    for(int d = 0; d <= 9; d++)
    for(int e = 1; e <= 9; e++)
    for(int f = 0; f <= 9; f++)
    for(int g = 0; g <= 9; g++)
    for(int h = 0; h <= 9; h++){
        memset(vis,0,sizeof(vis));
        vis[a] = 1;
        vis[b] = 1;
        vis[c] = 1;
        vis[d] = 1;
        vis[e] = 1;
        vis[f] = 1;
        vis[g] = 1;
        vis[h] = 1;
        int cnt = 0;
        for(int i = 0; i < 10; i++){
            if(vis[i])cnt++;
        }
        if(cnt != 8) continue;
        // printf("%d%d%d%d%d%d%d%d\n",a,b,c,d,e,f,g,h);
        if((a*1000+b*100+c*10+d) + (e*1000+f*100+g*10+b) == (e*10000+f*1000+c*100+b*10+h)){
            printf("%d%d%d%d\n",e,f,g,b);
            // return 0;
        }
    }
    return 0;
}