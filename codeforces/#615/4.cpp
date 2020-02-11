/*
 * @Date: 2020-01-22 23:56:56
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-23 00:14:08
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    map<int,int> M;
    int n,x;
    int t = 0;
    scanf("%d%d",&n,&x);
    M.clear();
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        if(a == t){
            printf("%d\n",++t);
        }
        else{
            M[a%x]++;
            while(M[t%x] > 0){
                M[t%x]--;
                t++;
            }
            printf("%d\n",t);
        }
        
    }
    return 0;
}