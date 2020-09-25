#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int cnt[1000010];
int main(){
    int n,x;
    cin >> n;
    int maxv = 0;
    for(int i = 0;  i < n; i++){
        cin >> x;
        maxv = max(maxv, x);
        int len = sqrt(x);
        for(int j = 1; j <= len; j++){
            if(x % j == 0){
                cnt[j]++;
                if(j * j != x) cnt[x/j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        //至少有i个数的因数为maxv，就为k的最大默契程度。
        //又因为i的答案一定大于等于i+1的答案，所以可以从后往前线性查找。
        while(cnt[maxv] < i) maxv--;
        cout << maxv << endl;
    }
    return 0;
}