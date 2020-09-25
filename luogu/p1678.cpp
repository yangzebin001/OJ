#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int MAXN = 1e5+10;
int n,m;
int school[MAXN], student[MAXN];
long long ans = 0;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> school[i];
    }
    sort(school+1, school+n+1);
    for(int i = 1; i <= m; i++){
        int a;
        cin >> a;
        int k = lower_bound(school+1, school+n+1, a) - school;
        if(k == n+1){
            ans += a-school[n];
        } else if(k == 1){
            ans += school[1]-a;
        } else {
            ans += min(school[k]-a,a-school[k-1]);
        }
    }
    cout << ans;
    return 0;
}