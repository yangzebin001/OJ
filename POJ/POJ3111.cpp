/*
 * @Date: 2019-10-02 16:13:50
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-02 17:01:37
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define EPS 1e-9
const int MAXN = 1e6+10;

struct node{
    int x,y,q;
    double s;
    bool operator <(const node &qq)const{
        return s > qq.s;
    }
}a[MAXN];

int N,K;

bool check(double aim){
    for(int i = 1; i <= N; i++){
        a[i].s = a[i].x - aim*a[i].y;
    }
    sort(a+1,a+N+1);
    double sum = 0;
    for(int i = 1; i <= K; i++){
        sum += a[i].s;
    }
    return sum >= 0;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 1; i <= N; i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].q = i;
    }
    double l = 0, r = 1e13+1;
    while(r - l > EPS ){
        double mid = (l + r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    for(int i = 1; i <= K; i++){
        cout << a[i].q << " ";
    }
    return 0;
}