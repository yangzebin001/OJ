/*
 * @Date: 2019-08-28 15:15:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-29 08:27:33
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100005;
const int MOD = 1000101;
vector<int> sum[MOD];
int arr[MAXN][6];

//顺时针
bool isOne(int a, int b, int k){
    for(int j = k,i = 0; i < 6; j=(j+1)%6,i++){
        if(arr[a][i] != arr[b][j]) return false;
    }
    return true;
}

//逆时针
bool isOne1(int a, int b, int k){
    for(int j = k,i = 5; i >= 0; j = (j+1)%6,i--){
        if(arr[a][i] != arr[b][j]) return false;
    }
    return true;
}

bool isSame(int a,int b){
    int flag = 0;
    for(int i = 0; i < 6; i++){
        if(isOne(a,b,i)) return true;
        if(isOne1(a,b,i)) return true;
    }
    return false;
}


int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int flag = 0;
    for(int i = 0; i < n; i++){
        int su = 0;
        for(int j = 0; j < 6; j++){
            scanf("%d",&arr[i][j]);
            su += arr[i][j];
        }
        if(flag) continue;
        for(int j = 0; j < sum[su%MOD].size(); j++){
            if(isSame(sum[su%MOD][j],i)){
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        sum[su%MOD].push_back(i);
    }
    if(flag) printf("Twin snowflakes found.");
    else printf("No two snowflakes are alike.\n");
    return 0;
}