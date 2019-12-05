/*
 * @Date: 2019-11-08 10:52:55
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-08 11:56:19
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<stack>
#include<vector>
using namespace std;
stack<int> stk;
int N;

vector<int> v;


int main(){
    freopen("in.txt","r",stdin);
    string op;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        cin >> op;
        if(op == "Pop"){
            if(stk.empty()){
                printf("Invalid\n");
                continue;
            }
            vector<int>::iterator it;
            it = lower_bound(v.begin(),v.end(),stk.top());
            v.erase(it);
            printf("%d\n",stk.top());
            stk.pop();
        }else if(op == "PeekMedian"){
            if(v.empty()){
                printf("Invalid\n");
                continue;
            }else{
                printf("%d\n",v[(v.size()-1)/2]);
            }
        }else if(op == "Push"){
            int a;
            cin >> a;
            stk.push(a);
            vector<int>::iterator it;
            it = lower_bound(v.begin(),v.end(),a);
            v.insert(it,a);
        }
    }
    // set<int>::iterator it;
    // for(it = s1.begin(); it != s1.end(); it++){
    //     printf("%d ",*it);
    // }
    // s1.insert(1);
    // s1.insert(2);
    // printf("%d",*(--s1.end()));
    // // printf("%d",*(s1.end()--));
    // // s1.erase(s1.begin());
    // // printf("%d",*(s1.begin()));
    return 0;
}