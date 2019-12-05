#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 4e5+10;
typedef long long LL;
LL arr[MAXN];
int main(){
    int N;
    scanf("%d",&N);
    int i = 0;
    for(; i < N; i++){
        scanf("%lld",&arr[i]);
    }
    scanf("%d",&N);
    for(int j = 0; j < N; j++,i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+i);
    printf("%lld",arr[(i-1)/2]);
    return 0;
}