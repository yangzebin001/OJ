/*
 * @Date: 2019-09-17 17:05:23
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-17 18:13:33
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int N,K,M;
const int MAXN = 1e5+10;
int dir[MAXN];
int f[MAXN];

int cal(int k){
    // 表示区间[i, i+k-1] 是否翻转
    memset(f,0,sizeof(f));
    int sum = 0;//区间内翻转的次数
    int res = 0;
    for(int i = 0; i + k-1 < N; i++){
        //对于当前牛，如果为正面，如果之前的数翻转了奇数次，则该牛也要翻转，
        //如果为反面，如果之前翻转了偶数次（相当于没翻转），则该牛也要翻转。
        //否则，如果当前牛是反面，且已经翻转了奇数次，或者当前牛是正面，且翻转了偶数次，则该牛都不需要翻转。（之前的次数已经决定了他是否已经翻转了）
        //总结一下就是当前数与之前翻转次数相加如果为奇数，则需要翻转。
        if((dir[i] + sum) % 2 != 0){
            res++;
            f[i] = 1;
        }
        //更新翻转次数
        sum += f[i];
        //固定区间
        if(i - k + 1 >= 0){
            sum -= f[i-k+1];
        }
    }
    //判断剩下的是否都已变为正面 ---->由于前n-k+1个 已经翻转了，只要剩下的判断是否需要继续翻转即可。
    for(int i = N-k+1; i < N; i++){
        if((dir[i] + sum) % 2 != 0) return -1;
        //固定区间
        if(i - k + 1 >= 0) sum -= f[i-k+1];
    }
    return res;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    K = 1, M = N;
    char c[3];
    for(int i = 0; i < N; i++){
        scanf("%s",c);
        if(c[0] == 'B') dir[i] = 1;
    }   
    for(int k = 1; k <= N; k++){
        int m = cal(k);
        if(m >= 0 && m < M){
            M = m;
            K = k;
        }
    }
    printf("%d %d",K,M);
}