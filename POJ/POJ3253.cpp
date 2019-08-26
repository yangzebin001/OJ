#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i = 0; i < n; i++){
        int a; scanf("%d",&a);
        pq.push(a);
    }
    long long ans = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    printf("%lld",ans);
    return 0;
}