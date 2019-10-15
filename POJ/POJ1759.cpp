/*
 * @Date: 2019-10-10 15:04:34
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-10 15:59:07
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1e3 + 5;
typedef long long LL;
int N;
double A;
double H[MAXN];
double ans;
bool check(double B){
    double a,b,c;
    a = A;
    b = B;
    for(int i = 0; i < N-2; i++){
        c = 2. * (b+1)-a;
        a = b;
        b = c;
        if(c < 0) return false;
    }
    ans = c;
    return true;

}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%lf",&N,&A);
    double l = -1, r = 1e17;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.2f\n",ans);
    return 0;
}
