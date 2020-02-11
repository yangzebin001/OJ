/*
 * @Date: 2020-01-25 20:18:48
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-25 21:52:21
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n;
char A[30],B[30],C[30];
int a[30],b[30],c[30],num[30],Next[30];
bool used[30];
int cnt;
bool judge(){
    for(int i = 0,x = 0; i < n; i++){
        int ca = num[a[i]], cb = num[b[i]], cc = num[c[i]];
        if((ca+cb+x)%n != cc) return false;
        x = (ca+cb+x)/n;
    }
    return true;
} 

bool canprune(){
    if(num[a[n-1]] + num[b[n-1]] >= n) return true; //最高位不能有进位
    for(int i = 0; i < n; i++){
        int ca = num[a[i]], cb = num[b[i]], cc = num[c[i]];
        if(ca == -1 || cb == -1 || cc == -1) continue;
        //当前位一定要符合(a+b+1)%n == c || (a+b+1)%n ==c
        if((ca+cb)%n != cc && (ca+cb+1)%n != cc) return true;
    }
    return false;
}

void dfs(int x){
    if(canprune()) return;
    if(x == n){
        if(judge()) {
            for(int i = 0; i < n; i++){
                printf("%d ",num[i]);
            }
            exit(0);
        }
    } 
    for(int i = n-1; i >= 0; i--){ //倒着搜会很快
        if(!used[i]){
            used[i] = true;
            //将下一个字符赋值
            num[Next[x]] = i;
            dfs(x+1);
            num[Next[x]] = -1;
            used[i] = false;
        }
    }
    return;
}
void getnext(int c){
    if(used[c] == false){
        Next[cnt++] = c;
        used[c] = true;
    }
    
}

int main(){
    scanf("%d%s%s%s",&n,&A,&B,&C);
    
    for(int i = 0; i < n; i++){
        //反着映射
        a[n-1-i] = A[i]-'A';
        b[n-1-i] = B[i]-'A';
        c[n-1-i] = C[i]-'A';
        num[i] = -1;
    }
    for(int i = 0; i < n; i++){
        //最早出现的先赋值
        getnext(a[i]);
        getnext(b[i]);
        getnext(c[i]);
    }
    for(int i = 0; i < n; i++) used[i] = false;
    dfs(0);
    return 0;
}