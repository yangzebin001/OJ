/*
 * @Date: 2019-10-16 21:31:02
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-29 17:28:47
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int,int> P;
struct C{
    int b,e,i,o;
    bool operator <(const C &q)const{
        return b < q.b;
    }
};
struct D{
    int b,e,i,o;
    D(int _b,int _e, int _i, int _o){
        b = _b;
        e = _e;
        i = _i;
        o = _o;
    }
    D(){};
    bool operator <(const D &q)const{
        return e > q.e;
    };
};
const int MAXN = 50010;
C a[MAXN];
int b[MAXN];
int N;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&a[i].b,&a[i].e);
        a[i].i = i;
    }
    sort(a,a+N);
    priority_queue<D> q;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(q.size() && q.top().e < a[i].b){
            // cout << q.top().e << endl;
            int t = q.top().o;
            b[q.top().i] = t;
            q.pop();
            q.push(D(a[i].b,a[i].e,a[i].i,t));
        }else{
            
            q.push(D(a[i].b,a[i].e,a[i].i,q.size()+1));
        }
        ans = max(ans,(int)q.size());
    }
    while(q.size()){
        b[q.top().i] = q.top().o;
        q.pop();
    }
    printf("%d\n",ans);
    for(int i = 0; i < N; i++) printf("%d\n",b[i]);
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 50010;
typedef pair<int,int> PII;
//PII存放牛的区间，int存放id。
pair<PII,int> cows[MAXN];
int id[MAXN];
int N;

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&cows[i].first.first,&cows[i].first.second);
        cows[i].second = i;
    }
    sort(cows,cows+N);
    //存放每一排最后一头牛的位置和id。
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    for(int i = 0; i < N; i++){
        if(heap.empty() || heap.top().first >= cows[i].first.first){
            //新增一排牛
            PII stall = {cows[i].first.second,heap.size()+1};
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }else{
            PII stall = heap.top();
            heap.pop();
            //更新结束区间最小的牛的区间。
            stall.first = cows[i].first.second;
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
    }
    cout << heap.size() << endl;
    for(int i = 0; i < N; i++) cout << id[i] << endl;
    return 0;
}
*/