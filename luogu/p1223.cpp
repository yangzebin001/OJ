/*
 * @Date: 2020-02-12 14:36:37
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-12 14:43:26
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct node{
    int wait,num;
    node(){};
}Node[1010];
int cmp(node a, node b){
    return a.wait < b.wait;
}
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> Node[i].wait;
        Node[i].num = i; 
    }
    sort(Node+1,Node+n+1,cmp);
    double totalwait = 0,cur = 0;
    for(int i = 1; i <= n; i++){
        printf("%d",Node[i].num);
        if(i != n){
            printf(" ");
            cur += Node[i].wait;
            totalwait += cur;

        }
    }
    printf("\n%.2f",totalwait/n);
    return 0;
}