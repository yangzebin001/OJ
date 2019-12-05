/*
 * @Date: 2019-10-28 14:44:55
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-29 10:15:54
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define INF 6666666
#define K 1001
#define N 21
#define T 9*60
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int n, m, k, q;
    int i,j,b,c;
    int process_time[K],leave_time[K] = {0},que_time[N] = {0};
    queue<int> que[N];
    cin >> n >> m >> k >>q;
    for(i = 0; i < k; i++) cin >> process_time[i];
    int top;
    for(i = 0, top = 0; top < n*m && top < k; ++top){
        que[i].push(top);
        leave_time[top] = que_time[i] + process_time[top];
        que_time[i] =leave_time[top];
        i = (i+1)%n;
    }

    int index,temp;
    int min_time = INF;
    for(;top < k; ++top){
        min_time = INF;
        for(i = 0; i < n; i++){
            temp = que[i].front();
            if(leave_time[temp] < min_time){
                min_time = leave_time[temp];
                index = i;
            }
        }
        que[index].pop();
        que[index].push(top);
        leave_time[top] = que_time[index] + process_time[top];
        que_time[index] = leave_time[top];
    }
    for(i = 0; i < q; i++){
        scanf("%d",&j);
        j--;
        if(leave_time[j] - process_time[j] >= T) printf("Sorry\n");
        else{
            printf("%02d:%02d\n",leave_time[j]/60+8,leave_time[j]%60);
        }
    }

    return 0;
}