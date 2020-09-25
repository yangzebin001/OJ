#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e6+10;

int cnt[MAXN];
int w[MAXN], arr[MAXN];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i = 1; i < MAXN; i++){
        if(!cnt[i]) continue; //小小的优化
        for(int j = i; j < MAXN; j += i){ //遍历i的倍数
            w[j] += cnt[i]; //i这个数会对j产生cnt[i]的贡献
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", w[arr[i]]-1);
    }
    return 0;
}