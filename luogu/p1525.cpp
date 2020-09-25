#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int F[20010<<1];
int n,m;
struct node{
    int x,y,v;
    node(){}
    node(int _x, int _y, int _v){
        x = _x;
        y = _y;
        v = _v;
    }
}Node[100010];

int getF(int a){
    return F[a] == a ? a : F[a] = getF(F[a]);
}

bool cmp(struct node &a, struct node &b){
    return a.v > b.v;
}
int main(){
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; i++) F[i] = i, F[i+n] = i+n;
    for(int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        Node[i].x = a;
        Node[i].y = b;
        Node[i].v = c;
    }
    //贪心，先将矛盾值大的分开放
    sort(Node, Node+m, cmp);
    for(int i = 0; i < m; i++){
        int a = getF(Node[i].x), b = getF(Node[i].y);
        int c = getF(Node[i].x+n), d = getF(Node[i].y+n);
        //如果a和b在同一监狱
        if(a == b || c == d){
            printf("%d\n", Node[i].v);
            return 0;
        }
        F[a] = d;  //a分配到监狱1， b分配到监狱2
        F[b] = c;  //b分配到监狱1， a分配到监狱2
    }
    putchar('0');
    return 0;
}