#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct node{
    int l, r;
}Node[1000100];

int n, l, r;

int getDepth(int root){
    if(Node[root].l == 0 && Node[root].r == 0) return 1;
    return max(getDepth(Node[root].l), getDepth(Node[root].r)) + 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> l >> r;
        Node[i].l = l;
        Node[i].r = r;
    }
    cout << getDepth(1);
    return 0;
}