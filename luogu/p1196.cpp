/*
 * @Date: 2020-02-11 16:02:33
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-11 17:21:22
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 30010;
int F[MAXN]; //存储该元素的代表结点（父节点）
int d[MAXN]; //该元素之前的元素的个数。
int len[MAXN]; //所在集合的元素数量
int getF(int x){
    if(F[x] == x) return x;
    int root = getF(F[x]); //先递归求父节点。
    d[x] += d[F[x]]; //统计当前元素之前的元素的个数
    return F[x] = root; //路径压缩
}
void _union(int x, int y){
    x = getF(x);
    y = getF(y);
    d[x] = len[y]; //根据题意，x集合要插到y集合的尾部，所以d[x]之前有(y集合的数量)个元素
    F[x] = y; //合并集合
    len[y] += len[x]; //维护当前集合的元素数量。
}
bool issame(int x, int y){
    return getF(x) == getF(y);
}
int getdis(int x, int y){
    if(!issame(x,y)) return -1;
    //返回两元素之间的元素个数。
    return abs(d[x]-d[y])-1;
}
int main(){
    for(int i = 0; i < MAXN; i++){
        len[i] = 1;
        d[i] = 0;
        F[i] = i;
    }
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        char c[2];
        int a,b;
        scanf("%s%d%d",&c,&a,&b);
        if(c[0] == 'M'){
            _union(a,b);
        }else{
            printf("%d\n",getdis(a,b));
        }
    }
    // printf("%d %d %d\n",d[4],d[3],d[2]);    
    return 0;
}