/*
 * @Date: 2020-01-14 15:08:06
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 16:05:59
 */
/*
 * @Date: 2020-01-14 15:08:06
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 15:23:26
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+10;
struct node{
    int num,score,force;
}Node[MAXN],T[MAXN];
void toT(int i,int j){
    T[i].num = Node[j].num;
    T[i].score = Node[j].score;
    T[i].force = Node[j].force;
}
void toN(int i,int j){
    Node[i].num = T[j].num;
    Node[i].score = T[j].score;
    Node[i].force = T[j].force;
}
int A[MAXN],B[MAXN];
int cmp(node&a, node &b){
    if(a.score == b.score) return a.num < b.num;
    return a.score > b.score;
}
int main(){
    freopen("in.txt","r",stdin);
    int n,r,q;
    scanf("%d%d%d",&n,&r,&q);
    for(int i = 0; i < 2*n; i++){
        scanf("%d",&Node[i].score);
        Node[i].num = i+1;
    }
    for(int i = 0; i < 2*n; i++){
        scanf("%d",&Node[i].force);
    }
    sort(Node,Node+2*n,cmp);
    // r = 1;
    while(r--){
        int ai = 0, bi = 0;
        for(int i = 0; i < 2*n; i+=2){
            if(Node[i].force > Node[i+1].force){
                Node[i].score++;
                A[ai] = i;
                ai++;
                B[bi] = i+1;
                bi++;
            }else if(Node[i].force < Node[i+1].force){
                A[ai] = i+1;
                ai++;
                Node[i+1].score++;
                B[bi] = i;
                bi++;
            }else if(Node[i].num < Node[i+1].num){
                Node[i].score++;
                A[ai] = i;
                ai++;
                B[bi] = i+1;
                bi++;
            }else{
                A[ai] = i+1;
                ai++;
                Node[i+1].score++;
                B[bi] = i;
                bi++;
            }
        }
        // for(int i = 0; i < bi; i++){
        //     cout << A[i] <<" ";
        // }
        int ci = 0, di = 0,cc = 0;
        while(ci < ai && di < bi){
            if(Node[A[ci]].score > Node[B[di]].score){
                toT(cc++,A[ci]);
                ci++;
            }else if(Node[A[ci]].score < Node[B[di]].score){
                toT(cc++,B[di]);
                di++;
            }else if(Node[A[ci]].num < Node[B[di]].num){
                toT(cc++,A[ci]);
                ci++;
            }else if(Node[A[ci]].num > Node[B[di]].num){
                toT(cc++,B[di]);
                di++;
            }
        }
        while(ci < ai){
            toT(cc++,A[ci]);
            ci++;
        }
        while(di < bi){
            toT(cc++,B[di]);
            di++;
        }
        for(int i = 0; i < 2*n; i++){
            toN(i,i);
        }
    }
    // for(int i = 0; i < 2*n; i++){
    //     cout << Node[i].num <<" " << Node[i].score << endl;
    // }
    printf("%d",Node[q-1].num);
    return 0;
}