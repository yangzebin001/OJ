/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-10 10:01:59 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-10 10:05:46
 */
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;

int n,m;
int w[30];
int ans = 0;

int num_one(int x){
    int cnt = 0;
    for(int i = 0; i <= n-1; i++){
        if(x & (1<<i)) cnt++;
    }
    return cnt;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < (1<<n); i++){
        if(num_one(i) == n-m){ //符合条件
            bitset<3000> v; //记录是否可以达到容量（下标）
            v[0] = 1; //初始化容量0
            for(int j = 0; j < n; j++){
                if(i & (1<<j)) //如果可以选这一位
                    v = v | v << w[j];
            }
            ans = max(ans, (int)v.count());
        }
    }
    cout << ans - 1 << endl; //舍弃容量0
    return 0;
}