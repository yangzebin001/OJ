/*
 * @Date: 2019-10-13 16:43:41
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-13 17:35:58
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN = 1e6+10;
int f[MAXN]; //保存当前位置最大的前缀和，
int sum[MAXN]; //保存当前位置的前缀和。
int p1; //当前位置。
int p2;
int s1[MAXN],s2[MAXN];
const int INF = 0x3f3f3f3f;

char op[4];
int N;
int main(){
    //freopen("in.txt","r",stdin);
    f[0] = -INF;
    while(scanf("%d",&N) != EOF && N){
        p1 = 1;
        p2 = 1;
        for(int i = 0; i < N; i++){
            scanf("%s",op);
            int a;
            if(op[0] == 'I' || op[0] == 'Q'){
                scanf("%d",&a);
                if(op[0] == 'I'){
                    s1[p1] = a;
                    sum[p1] = sum[p1-1] + a;
                    f[p1] = max(f[p1-1],sum[p1]);
                    p1++;
                }else{
                    if(a > p1) a = p1;
                    printf("%d\n",f[a]);
                }
            }else if(op[0] == 'L'){
                if(p1 <= 1) continue;
                s2[p2++] = s1[--p1];
            }else if(op[0] == 'R'){
                if(p2 <= 1) continue;
                s1[p1] = s2[--p2];
                sum[p1] = sum[p1-1] + s1[p1];
                f[p1] = max(f[p1-1],sum[p1]);
                p1++;
            }else if(op[0] == 'D'){
                if(p1 <= 1) continue;
                p1--;
            }
        }
    }
    return 0;
}