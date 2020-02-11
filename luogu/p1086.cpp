/*
 * @Date: 2020-01-26 14:08:37
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-26 18:26:18
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    int x,y,num;
}Node[400];
int cmp(node &a, node &b){
    return a.num > b.num;
}
int dis(node &a, node &b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}
int t;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a;
            scanf("%d",&a);
            if(a){
                Node[t].x = i;
                Node[t].y = j;
                Node[t++].num = a;
            }
        }
    }
    sort(Node,Node+t,cmp);
    if(Node[0].x*2+1 > k){
        printf("0\n");
        return 0;
    }
    k -= (Node[0].x+1);
    int ans = Node[0].num;
    int c = 1;
    while(c < t){
        int needtime = dis(Node[c],Node[c-1])+1+Node[c].x;
        if(needtime <= k){
            ans += Node[c].num;
            k -= dis(Node[c],Node[c-1])+1;
            c++;
        }else{break;}
    }
    printf("%d",ans);
    return 0;
}