/*
 * @Date: 2019-11-15 21:37:32
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-15 21:50:40
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
const int MAXN = 1e5+10;
struct ListNode{
    int data,cur,next;
}node[MAXN];
deque<ListNode> q;
vector<ListNode> v;
int main(){
    freopen("in.txt","r",stdin);
    int first,N;
    scanf("%d%d",&first,&N);
    for(int i = 0; i < N; i++){
        int cur, data, next;
        scanf("%d%d%d",&cur,&data,&next);
        node[cur].cur = cur;
        node[cur].data = data;
        node[cur].next = next;
        // printf("%d\n",data);
    }
    int curp = first;
    while(curp != -1){
        q.push_back(node[curp]);
        curp = node[curp].next;
    }
    while(q.size()){
        v.push_back(q.back());
        q.pop_back();
        if(q.size()){
            v.push_back(q.front());
            q.pop_front();
        }
    }
    for(int i = 0; i < v.size()-1; i++){
        printf("%05d %d %05d\n",v[i].cur,v[i].data,v[i+1].cur);
    }
    if(v.size()) printf("%05d %d -1\n",v[v.size()-1].cur,v[v.size()-1].data);
    return 0;
}