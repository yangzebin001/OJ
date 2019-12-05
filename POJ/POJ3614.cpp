/*
 * @Date: 2019-03-16 19:53:04
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-23 21:08:28
 */
#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
#define maxn 3000
#define P pair<int, int> 
using namespace std;

P cow[maxn],bot[maxn];
int main(){
	priority_queue<int, vector<int>, greater<int> > pq;
	int ans = 0;
	int C,L;
	cin >> C >> L;
	for(int i = 0; i < C; i++){
		scanf("%d%d",&cow[i].first,&cow[i].second);
	}
	for(int i = 0; i < L; i++){
		scanf("%d%d",&bot[i].first,&bot[i].second);
	}
	
	sort(cow,cow+C);
	sort(bot,bot+L);
	int j = 0;
	for(int i = 0; i < L; i++){
		while(cow[j].first <= bot[i].first && j < C){
			pq.push(cow[j].second);
			j++;
		}
		while(!pq.empty() && bot[i].second){
			int x = pq.top();
			pq.pop();
			if(x < bot[i].first) continue;
			bot[i].second--;
			ans++;
		}
	}
	cout << ans;
	return 0;
	 
} 

/*
//平衡树版
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN = 2510;
typedef pair<int,int> PII;
int N,M;
PII cows[MAXN];
int main(){
    cin >> N >>M;
    for(int i = 0; i < N; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows,cows+N);
    map<int,int> spfa;
    for(int i = 0; i < M; i++){
        int spa,cover;
        cin >> spa >> cover;
        spfa[spa] += cover;
    }
    spfa[0] = spfa[1001] = N;
    int ans = 0;
    for(int i = N-1; i >= 0; i--){
        map<int,int>::iterator it = spfa.upper_bound(cows[i].second);
        --it;
        if(cows[i].first <= it->first && cows[i].second >= it->first){
            ans++;
            if(-- it->second == 0) spfa.erase(it);
        }
    }
    cout << ans;
    return 0;
}
*/
/*
//暴力版
#include<iostream>
#include<utility>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int MAXN = 5000+10;
int C,L;
PII p[MAXN];
PII q[MAXN];
int main(){
    int ans = 0;
    scanf("%d%d",&C,&L);
    for(int i = 0; i < C; i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    sort(p,p+C);
    for(int i = 0; i < L; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        q[i].first = a;
        q[i].second = b;
    }
    sort(q,q+L);
	//从开始位置大到小考察每头牛。
    for(int i = C-1; i >= 0; i--){
		//同样，对于每头牛，考察在该牛区间内最右的防晒霜。
        for(int j = L-1; j >= 0; j--){
            if(q[j].second > 0 && q[j].first >= p[i].first && q[j].first <= p[i].second){
                ans++;
                q[j].second--;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

*/