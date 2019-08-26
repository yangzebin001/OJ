/*
 * @Author: BeckoninGshy 
 * @Date: 2019-08-24 11:19:07 
 * @Last Modified by:   BeckoninGshy 
 * @Last Modified time: 2019-08-24 11:19:07 
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 30;
const int INF = 0x3f3f3f3f;

int n;
int M[MAXN][MAXN];
int ans;
int curans;
int add1[MAXN];
void addto1(int k){
    add1[k] = 1;
    //将该点与0网络的所有边相连，与1网络的所有边解除连接
    for(int i = 0; i < n; i++){
        if(!add1[i]) curans += M[i][k];
        else curans -= M[i][k];
    }
}


int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&M[i][j]);
        }
    }
    //由于1001 与0110是一样的，所以枚举前2的n-1即可。剪了一半枝
    for(int i = 0; i < 1<<(n-1); i++){
        memset(add1,0,sizeof(add1));
        curans = 0;
        for(int k = 0; k < n; k++){
            if(i >> k & 1){
                addto1(k);
            }
            // printf("%d\n",curans);
        }
        ans = max(curans,ans);
    }
    printf("%d",ans);
    return 0;
}