#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b;

struct node{
    int l = -1,r = -1;
    char data;
}Node[100];

int dfs(int l, int r, int &bidx){
    if(l > r) return -1;
    int c = l;
    for(; a[c] != b[bidx]; c++);
    Node[c].data = b[bidx++];
    Node[c].l = dfs(l, c-1, bidx);
    Node[c].r = dfs(c+1, r, bidx);
    return c;
}

void postorder(int root){
    if(Node[root].l == -1 && Node[root].r == -1){
        cout << Node[root].data;
        return;
    }
    if(Node[root].l != -1) postorder(Node[root].l);
    if(Node[root].r != -1) postorder(Node[root].r);
    cout << Node[root].data;
}

int main(){
    cin >> a >> b;
    int n = a.size();
    int bidx = 0;
    dfs(0,n-1,bidx);
    int c = 0;
    while(a[c] != b[0]) c++;
    postorder(c);
    return 0;
}