/*
 * @Date: 2019-11-20 19:45:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-20 19:59:59
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int MAXN = 1e5+10;
typedef long long LL;
LL F[MAXN];
double C[MAXN];
int N,k,a;
double z,r;
map<int,int> M;

double dfs(int t){
    if(t == 0) return z;
    if(C[t] != 0) return C[t];
    return C[t] = dfs(F[t])*((100.0-r)/100.0);
}

int main(){
    freopen("in.txt","r",stdin);
    memset(F,-1,sizeof(F));
    scanf("%d%lf%lf",&N,&z,&r);
    for(int i = 0; i < N; i++){
        scanf("%d",&k);
        if(k == 0){
            scanf("%d",&a);
            M[i] = a;
        }
        else{
            for(int j = 0; j < k; j++){
                scanf("%d",&a);
                F[a] = i;
            }
        }
    }
    double sum = 0;
    map<int,int>::iterator it;
    for(it = M.begin(); it != M.end(); it++){
        sum += dfs(it->first)*(it->second);
    }
    printf("%.0f",sum-0.5);
    return 0;
}
