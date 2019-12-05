/*
 * @Date: 2019-11-09 16:59:04
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-09 17:40:02
 */
#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+10;
struct node{
    int data;
    int next;
    int cur;
}List[MAXN];
map<int,bool> M;
int root,N;
vector<node> V;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&root,&N);
    for(int i = 1; i <= N; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        List[a].data = b;
        List[a].next = c;
        List[a].cur = a;
    }
    List[MAXN-1].next = root;
    int troot = MAXN-1;
    
    while(List[troot].next != -1){
        // printf("%d ",List[List[troot].next].data);
        if(M[abs(List[List[troot].next].data)]){
            V.push_back(List[List[troot].next]);
            List[troot].next = List[List[troot].next].next;
        }else{
            M[abs(List[List[troot].next].data)] = true;
            troot = List[troot].next;
        }
    }
    troot = MAXN-1;
    while(List[troot].next != -1){
        if(List[List[troot].next].next == -1){
            printf("%05d %d -1\n",List[troot].next,List[List[troot].next].data);
        }else{

            printf("%05d %d %05d\n",List[troot].next,List[List[troot].next].data,List[List[troot].next].next);
        }
        troot = List[troot].next;
    }
    if(V.size()) printf("%05d %d",0,V[0].data);
    for(int i = 1; i < V.size(); i++){
        printf(" %05d\n%05d %d",V[i].cur,V[i].cur,V[i].data);
    }
    if(V.size()) printf("-1\n");
    return 0;
}