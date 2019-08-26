#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int v[5];
int vis[123][123][123];


struct node{
    int v[5];
    int step;
    node(){}
};
node temp;

void pour(int a,int b){
    int sum = temp.v[a] + temp.v[b];
    if(sum >= v[b]){
        temp.v[b] = v[b];
    }else{
        temp.v[b] = sum;
    }
    temp.v[a] = sum - temp.v[b];
}
void bfs(){
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node num;
    num.v[1] = v[1];num.v[2] = 0;num.v[3] = 0;num.step = 0;
    q.push(num);
    vis[v[1]][0][0] = 1;
    while(q.size()){
        num = q.front();q.pop();
        // printf("%d %d %d\n",num.v[1],num.v[2],num.v[3]);
        if(num.v[1] == num.v[2] && num.v[3] == 0){
            printf("%d\n",num.step);
            return;
        }
        for(int i = 1; i < 4; i++){
            for(int j = 1; j < 4; j++){
                if(i == j) continue;
                temp = num;
                pour(i,j);
                if(!vis[temp.v[1]][temp.v[2]][temp.v[3]]){
                    vis[temp.v[1]][temp.v[2]][temp.v[3]] = 1;
                    temp.step++;
                    q.push(temp);
                }
            }
        }
    }
    printf("NO\n");
}

int main(){
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&v[1],&v[2],&v[3]) && v[1] && v[2] && v[3]){
        if(v[1] % 2){
            printf("NO\n");
        }else{
            if(v[2] < v[3]) swap(v[2],v[3]);
            bfs();
        }
    }
    return 0;
}