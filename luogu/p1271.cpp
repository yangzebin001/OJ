#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int cnt[1010];

int n,m, a, tot;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        cnt[a]++;
    }
    for(int i = 0; i <= n; i++){
        while(cnt[i]){
            printf("%d ", i);
            cnt[i]--;
        }
    }
    
    return 0;
}