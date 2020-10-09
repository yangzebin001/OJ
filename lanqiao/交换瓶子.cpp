#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1000010;
long long arr[N];
long long maxn[N];
long long n,ans;

long long get(long long x){
	if(x < N){
		if(maxn[x]) return maxn[x];
	} 
	if(x == 1) return 1;
	long long t = x; 
	if(x % 2) t = max(get(x*3+1),t);
	else t = max(get(x>>1),t);
	if(x < N){
		maxn[x] = t;
	}
	return t;
}

int main(){
	cin >> n;
	
	for(int i = 2; i < n; i++){
		ans = max(ans,get(i));
	}
	cout << ans;
	return 0;
} 
