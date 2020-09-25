#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000010];
int main(){
    int t;
    scanf("%d",&t);
    int n,k;
    scanf("%d%d",&n,&k);
    int res=0,mi=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x;
        mi=min(mi,x);
        scanf("%d",&x);
        res+=abs(k-x);
    }
    res+=(k+mi-2);
    printf("%d\n",res);
    return 0;
}