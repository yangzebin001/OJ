/*
 * @Date: 2019-12-14 21:19:51
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-12-16 09:44:47
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 100009;
struct node{
    int d = 0;
    node *next = NULL;
    node *before = NULL;
}Node[MAXN];
bool ear[MAXN]; //标记该点是否被删除
int N,M,x,y,k,p,c;
int head = 1;
void ins(int k,int p, int c){
    Node[c].d = c;
    //插到k的后面
    if(p){
        Node[c].next = Node[k].next;
        Node[c].before = &Node[k];
        if(Node[k].next){
            Node[k].next->before = &Node[c];
        }
        Node[k].next = &Node[c];
    //插到k的前面
    }else{
        Node[c].next = &Node[k];
        Node[c].before = Node[k].before;
        if(Node[k].before){
            Node[k].before->next = &Node[c];
        }else{
            head = c;
        }
        Node[k].before = &Node[c];
    }
}
void del(int k){
    if(!ear[k]){
        ear[k] = true;
        if(Node[k].d != 0){
            Node[k].d = 0;
        }
    }
}
int main(){
    cin >> N;
    Node[1].d = 1;
    for(int i = 2; i <= N; i++){
        cin >> k >> p;
        ins(k,p,i);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> k;
        del(k);
    }
    bool flag = 0;
    for(node* a = &Node[head]; a; a = a->next){
        
        if(a->d){
            if(flag){
                cout << " "; 
            }
            cout << a->d ;
        }
        flag = 1;

    }
    
    return 0;
}