/*
 * @Date: 2019-10-18 19:44:27
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-19 10:31:58
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
using namespace std;
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(){}
    ListNode(int a){
        val = a;
        next = NULL;
    }
};
const int MAXN = 1e5+10;
int P,M,N;
int arr[MAXN];

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = NULL;
    ListNode* l = head;
    l = sortList(l);
    mid = sortList(mid);
    ListNode* newhead = new ListNode(0);
    ListNode* rn = newhead;
    while(l && mid){
        if(l->val < mid->val){
            newhead->next = l;
            l = l->next;
        }else{
            newhead->next = mid;
            mid = mid->next;
        }
        newhead = newhead->next;
    }
    newhead->next = l != NULL ? l : mid;
    return rn->next;
}

int main(){
    scanf("%d",&P);
    while(P--){
        map<int,ListNode*> m;
        scanf("%d%d",&N,&M);
        printf("%d %d\n",N,(M+1)/2);
        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        ListNode* now = head;
        for(int i = 0; i < M; i++){
            scanf("%d",arr[i]);
            ListNode* a = (ListNode*)malloc(sizeof(ListNode));
            a->val = arr[i];
            head->next = a;
            head = a;
            m[arr[i]] = a;
        }
        now->next = sortList(now->next);
    }
    return 0;
}