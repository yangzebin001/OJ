/*
 * @Date: 2020-01-14 12:06:14
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 12:26:43
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 2e4+10;
struct f{
    int num,W,E;
    f(){};
    f(int _n, int _w, int _e):num(_n),W(_w),E(_e){};
};
f Node[MAXN];
int cmp(f &a, f &b){
    if(a.W == b.W) return a.num < b.num;
    return a.W > b.W;
}
int cmp2(f &a, f &b){
    if(a.E == b.E) return a.num < b.num;
    return a.E > b.E;
}
int valE[20];
int n,k;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i = 0; i < 10; i++){
        scanf("%d",&valE[i]);
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d",&Node[i].W);
        Node[i].num = i+1;
    }
    sort(Node,Node+n,cmp);
    for(int i = 0; i < n; i++){
        Node[i].E = Node[i].W+valE[i%10];
    }
    sort(Node,Node+n,cmp2);
    for(int i = 0; i < k; i++){
        if(i != 0) printf(" ");
        printf("%d",Node[i].num);
    }
    return 0;
}