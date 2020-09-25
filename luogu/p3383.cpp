#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool is_prime[100000001];
int prime[100000001];
int cnt,n,q;
int main(){
    scanf("%d%d",&n,&q);
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++){
            //将前面的素数的倍数标记
            is_prime[i*prime[j]] = 0;
            if(i % prime[j] == 0) break; //i中也含有Prime[j]这个因子
        }
    }
    for(int i = 0; i < q; i++){
        int a;
        scanf("%d", &a);
        printf("%d\n", prime[a]);
    }
    return 0;
}