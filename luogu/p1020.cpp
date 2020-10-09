#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
int arr[MAXN],dp1[MAXN];//求不上升序列长度
int dp2[MAXN];//求上升序列长度
/*
对于问二求整个数列的最长上升子序列即可。证明如下：

（1）假设打导弹的方法是这样的：取任意一个导弹，从这个导弹开始将能打的导弹全部打完。而这些导弹全部记为为同一组，再在没打下来的导弹中任选一个重复上述步骤，直到打完所有导弹。

（2）假设我们得到了最小划分的K组导弹，从第a(1<=a<=K)组导弹中任取一个导弹，必定可以从a+1组中找到一个导弹的高度比这个导弹高（因为假如找不到，那么它就是比a+1组中任意一个导更高，在打第a组时应该会把a+1组所有导弹一起打下而不是另归为第a+1组），同样从a+1组到a+2组也是如此。那么就可以从前往后在每一组导弹中找一个更高的连起来，连成一条上升子序列，其长度即为K;

（3）设最长上升子序列长度为P，则有K<=P;又因为最长上升子序列中任意两个不在同一组内(否则不满足单调不升)，则有

P>=K，所以K=P。
*/
int N,len1,len2,t;
bool cmp(int a,int b){ return a > b;}
int main(){
    // t = 1;
    // len1 = len2 = 1;
    // freopen("in.txt","r",stdin);
    while(scanf("%d",&arr[t]) != EOF) t++;
    dp1[0] = dp2[0] = arr[0]; 
    for(int i = 1; i < t; i++){
        if(arr[i] <= dp1[len1]) dp1[++len1] = arr[i];
        else{
            int p = upper_bound(dp1,dp1+len1,arr[i],cmp)-dp1;
            dp1[p] = arr[i];
        }

        if(arr[i] > dp2[len2]) dp2[++len2] = arr[i];
        else{
            int p2 = lower_bound(dp2,dp2+len2,arr[i]) - dp2;
            dp2[p2] = arr[i];
        }
        for(int j = 0; j <= len2; j++){
            printf("%d ",dp2[j]);
        }
        printf("\n");
    }
    
    printf("%d\n%d",len1+1,len2+1);
    return 0;
}