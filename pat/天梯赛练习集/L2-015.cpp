/*
 * @Date: 2019-11-15 21:53:16
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-15 22:01:34
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e4+10;
vector<double> v;
int main(){
    freopen("in.txt","r",stdin);
    int N,K,M;
    scanf("%d%d%d",&N,&K,&M);
    
    for(int i = 0; i < N; i++){
        int min_s = 101,max_s = -1;
        double sum = 0,a;
        for(int j = 0; j < K; j++){
            scanf("%lf",&a);
            if(a < min_s) min_s = a;
            if(a > max_s) max_s = a;
            sum += a;
        }
        sum -= min_s;
        sum -= max_s;
        sum /= K-2;
        v.push_back(sum);
    }
    sort(v.begin(),v.end());
    for(int i = v.size()-M; i < v.size(); i++){
        if(i != v.size()-M) printf(" ");
        printf("%.3f",v[i]);
    }
    return 0;
}