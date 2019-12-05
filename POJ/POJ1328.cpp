/*
 * @Date: 2019-10-16 19:12:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-16 21:11:31
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1010;
int N,D;
struct P{
    double x,y;
    bool operator <(const P &q)const{
        return x < q.x;
    }
};
P point[MAXN];

//给定点在x轴上的左边界
double getpoint1(double x1,double y1){
    return x1-sqrt(fabs(D*D-y1*y1));
}
//给定点在x轴上的右边界
double getpoint2(double x1,double y1){
    return x1+sqrt(fabs(D*D-y1*y1));
}

int main()
{
    freopen("in.txt","r",stdin);
    int C = 0;
    while(scanf("%d%d",&N,&D)!=EOF && N && D){
        int cnt = 1,flag = 0;
        double p = 0.0;
        for(int i = 0; i < N; i++){
            scanf("%lf%lf",&point[i].x,&point[i].y);
            if(point[i].y > D || point[i].y < 0) flag = 1;
        }
        if(flag == 1){
            printf("Case %d: -1\n",++C);
            continue;
        }
        //先排序
        sort(point,point+N);
        //先尽可能往远处安放。
        p = getpoint2(point[0].x,point[0].y);
        for(int i = 1; i < N; i++){
            //超过了当前雷达的监控范围，需要增加雷达。
            if((p < getpoint1(point[i].x,point[i].y))){
                p = getpoint2(point[i].x,point[i].y);
                cnt++;
            }else{
                //尽可能容纳更多的建筑物
                p = min(p,getpoint2(point[i].x,point[i].y));
            }
        }
        printf("Case %d: %d\n",++C,cnt);
    }
    return 0;
}
