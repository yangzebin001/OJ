#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

multiset<int> s;
multiset<int>::iterator it;
int n, ans, x;
int main(){
    s.insert(INT_MIN);
    s.insert(INT_MAX);  //避免越界
    scanf("%d%d", &n, &ans);
    s.insert(ans);
    for(int i = 1; i < n; i++){
        scanf("%d", &x);
        it = s.insert(x); //multiset.insert可以直接返回iterator。
        it--;
        int l = *it;
        it++; it++;
        int r = *it;
        if(l == INT_MIN) ans += (r - x);
        else if(r == INT_MAX) ans += (x -l);
        else ans += min((r-x), (x-l));
    }
    printf("%d", ans);
    return 0;
}