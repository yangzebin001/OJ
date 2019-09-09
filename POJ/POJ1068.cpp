/*
 * @Date: 2019-09-07 17:28:03
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-07 18:27:05
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int N;
const int MAXN = 50;
int a[MAXN];
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int k = 0; k < N; k++){
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        //j:当前位置，u:相对位置，
        int j = 0,u = 0;
        for(int i = 0; i < n; i++){
            //新的相对位置
            int t;
            scanf("%d",&t);
            a[j+(t-u)] = 1;
            j = j+t-u+1;
            u = t;
        }
        // for(int i = 0; i < 2*n; i++) printf("%c ",'('+a[i]);
        // printf("\n");
        stack<int> s;
        //碰到的右括号个数
        int t = 0;
        for(int i = 0; i < 2*n; i++){
            //碰到了右括号
            if(a[i] == 1){
                //先将中间夹着的括号对加起来
                while(s.top() < 0) t -= s.top(),s.pop();
                //所匹配的左括号
                s.pop();
                printf("%d ", t + 1);
                //将中间的括号对加上该对。
                s.push(-t-1);
                //清空临时变量。
                t = 0;
            }else if(a[i] == 0){
                s.push(0);
            }
        }
        printf("\n");
    }
 
    return 0;
}