/*
 * @Date: 2019-11-15 20:31:39
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-15 21:30:13
 */
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int MAXN = 1010;
int N;
int seq[MAXN];
stack<int> s;
int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d",&N) && N){
        while(1){
            while(s.size()) s.pop();
            int t = 1;
            int k = 0;
            int flag = 0;
            for(int i = 0; i < N; i++){
                int a;
                scanf("%d",&a);
                seq[i] = a;
                if(a == 0 && i == 0){flag = 1; break;}
            }
            if(flag) break;
            while(k < N && t <= N){
                if(t == seq[k]){
                    t++; k++;
                }else if(s.size() && s.top() == seq[k]){
                    k++;
                    s.pop();
                }else{
                    s.push(t++); 
                }

            }
            while(s.size() && s.top() == seq[k]){ k++;s.pop();}
            if(k != N || s.size()){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }     
        printf("\n");
    }
    return 0;
}