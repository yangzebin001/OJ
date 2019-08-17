#include<iostream>
#include<cstdio>

int cnt[51];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i = 0; i < 51; i++){
        if(cnt[i]!=0) printf("%d:%d\n",i,cnt[i]);
    }
    return 0;
}