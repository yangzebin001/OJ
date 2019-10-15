/*
 * @Date: 2019-10-15 11:11:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-15 11:16:37
 */
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e7+10;
int N,M,a;
char op[100];
int c = 0;
int mm[MAXN];
int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&N)!= EOF && N){
        printf("Scenario #%d\n",++c);
        queue<int> qlist[N+1];
        for(int i = 0; i < N; i++){
            scanf("%d",&M);
            for(int j = 0; j < M; j++){
                scanf("%d",&a);
                mm[a] = i+1;
            }
            
        }
        
        while(scanf("%s",op)!= EOF && strcmp(op,"STOP") != 0){
            if(strcmp(op,"ENQUEUE") == 0){
                scanf("%d",&a);
                if(qlist[mm[a]].size() == 0) qlist[0].push(mm[a]);
                qlist[mm[a]].push(a);
                
            }else{
                if(qlist[0].empty()) continue;
                if(qlist[qlist[0].front()].size()){
                    printf("%d\n",qlist[qlist[0].front()].front());
                    qlist[qlist[0].front()].pop();
                    if(qlist[qlist[0].front()].empty()) {
                        qlist[0].pop();
                    }
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}