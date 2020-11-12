#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100010;
struct point{
    int s,id;
}record[MAXN];

bool cmp(point &a, point &b){
    return a.s < b.s;
}
int n,d,k;
int cnt[MAXN];

int main(){
    set<int> ans;
    scanf("%d%d%d",&n,&d,&k);
    for(int i = 0; i < n; i++){
        scanf("%d%d",&record[i].s,&record[i].id);
    }
    sort(record, record+n, cmp);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n && record[j].s - record[i].s < d){
            cnt[record[j].id]++;  //j与i在合法区间内
            if(cnt[record[j].id] >= k) ans.insert(record[j].id); 
            j++;
        }
        cnt[record[i].id]--; //窗口滑动
    }
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
        printf("%d\n",*it);
    }
    return 0;
}