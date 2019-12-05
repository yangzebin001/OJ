/*
 * @Date: 2019-11-08 19:26:15
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-08 19:42:08
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 110;
const int MAXM = 20010;
int arr[MAXN];
int vis[MAXM];
int N;
int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                if(arr[i] + arr[j] == arr[k] && !vis[arr[k]]){ 
                    ans++;
                    vis[arr[k]] = 1;
                    break;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}