#include<iostream>
#include<algorithm>

using namespace std;
int n,a,b;
unsigned long long C[110][110], ans;



int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i = 0; i <= 100; i++) C[i][0] = C[i][i] = 1;
    for(int i = 2; i <= 100; i++){
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }


    // 黑球白球互不影响，所以乘法原理
    // 考虑一种球：
    // k个球之间形成了k-1个间隙，我们将n-1个隔板插入间隙中，
    // 隔板就将球分为了k份，符合假设。
    // 这样从k-1个间隙中选出n-1个插入隔板 --> C(n-1)(k-1)
    // 盒子分不到球，添加n个**空球**， --> C(n-1)(k+n-1);
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            ans += C[n+i-1][n-1] * C[n+j-1][n-1];
        }
    }

    printf("%llu", ans);
    return 0;
}