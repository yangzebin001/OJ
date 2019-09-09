/*
 * @Date: 2019-09-03 18:11:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-04 09:31:14
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1000000+10;
int q1[MAXN],q2[MAXN];

int num[MAXN], n,k, minAns[MAXN],maxAns[MAXN];

int main(){
    freopen("in.txt","r", stdin);
    while(scanf("%d%d",&n,&k) != EOF){
        int head1 = 1, tail1 = 1, head2 = 1, tail2 = 1;
        for(int i = 1; i <= n; i++){
            //队首不在滑窗范围内则删去（在i = k+1的时机开始，每次删除一个）
            if(tail1 > head1 && q1[head1] <= i-k) head1++;
            if(tail2 > head2 && q2[head2] <= i-k) head2++;
            scanf("%d",&num[i]);
            //删去队尾不符合单调的值 并加入新值
            while(tail1 > head1 && num[i] <= num[q1[tail1-1]]) tail1--;
            q1[tail1++] = i;
            while(tail2 > head2 && num[i] >= num[q2[tail2-1]]) tail2--;
            q2[tail2++] = i;

            // 存储单调队列起始位置到答案数组（有效数字从k开始）
            minAns[i] = num[q1[head1]];
            maxAns[i] = num[q2[head2]];
        }
        for(int i = k; i <= n; i++)
            printf("%d ",minAns[i]);
        printf("\n");
        for(int i = k; i <= n; i++)
            printf("%d ",maxAns[i]);
        printf("\n");
    
    }
    return 0;
}
