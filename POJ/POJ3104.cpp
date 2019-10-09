/*
 * @Date: 2019-09-26 15:33:24
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-27 22:46:54
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN = 100000+10;
int N,K;//k为烘干机的烘干时间
int nums[MAXN];

bool check(int time){
    int t = 0,j = 0;
    for(int i = N-1; i >= 0; i--){
        //如果所需时间小于目标时间，可以忽略。否则计算剩余时间
        t = max(nums[i]-time,0);
        //向上取整时间
        j = j+ceil(t*1.0/(K-1));
        if(j > time) return false;
    }
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    int maxi = -1;
    char ss[10000];
    while(scanf("%d",&N) != EOF){
        
        int t;
        for(int i = 0; i < N; i++){
            scanf("%d",&nums[i]);
            maxi = max(maxi,nums[i]);
        }
        // sort(nums,nums+N);
        scanf("%d",&K);
        if(K == 1) {
            printf("%d\n",maxi);
            continue;
        }
        int l = 1, r = 1e9;
        while(l < r){
            int mid = l+r >>1;
            if(check(mid)) r = mid;
            else l = mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}