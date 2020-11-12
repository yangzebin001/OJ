/*
 * @Author: BeckoninGshy 
 * @Date: 2020-10-14 18:28:27 
 * @Last Modified by: BeckoninGshy
 * @Last Modified time: 2020-10-14 19:57:58
 */
#include<bits/stdc++.h>
using namespace std;

bool inq[100010];
int last[100010];
int score[100010];

pair<int,int> orders[100010];
int n,m,t;
int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
        cin >> orders[i].first >> orders[i].second; 
    }
    sort(orders, orders+m);
    for(int i = 0; i < m && orders[i].first <= t; i++){
        int j = i;
        while(j < m && orders[j] == orders[i]) j++;
        int ts = orders[i].first, id = orders[i].second;
        score[id] -= ts-last[id]-1; //减去当前时间到上一时间之内的时间 (last[i],ts)
        if(score[id] < 0) score[id] = 0;
        if(score[id] <= 3) inq[id] = false;
        last[id] = ts;

        score[id] += (j-i)*2; //加上当前时间内获得的优先级
        if(score[id] > 5) inq[id] = true;
        i = j-1;
    }
    for(int i = 1; i <= n; i++){
        if(last[i] < t){
            score[i] -= t-last[i]; //让没有到当前时间的订单到当前时间
            if(score[i] <= 3) inq[i] = false;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res += inq[i];
    cout << res << endl;
    return 0;
}