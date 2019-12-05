/*
 * @Date: 2019-10-26 14:46:40
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-26 15:53:58
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int rest[7];
int main(){
    freopen("in.txt","r",stdin);
    int sum = 0;
    
    while(1){
        sum = 0;
        int ans = 0;
        for(int i = 1; i <= 6; i++) scanf("%d",&rest[i]),sum += rest[i];
        if(sum == 0) break;
        ans += rest[6];
        rest[6] = 0;
        int cnt = 36;
        //选第五
        while(rest[5]){
            rest[5]--;
            cnt -= 25;
            if(rest[1] > cnt) rest[1] -= cnt;
            else rest[1] = 0;
            ans++;
            cnt = 36;
        }
        //选四尽量选2，然后选1
        while(rest[4]){
            rest[4]--;
            cnt -= 16;
            int t = cnt/4;
            if(rest[2] > t) rest[2] -= t,cnt = 0;
            else cnt -=(rest[2]*4),rest[2] = 0;
            if(rest[1] > cnt) rest[1] -= cnt,cnt = 0;
            else cnt -=(rest[1]),rest[1] = 0;
            ans++;
            cnt = 36;
        }
        //选三，然后选二号箱，二号箱最多能选(剩余空间/4-1)个，接着尽量选1号箱
        if(rest[3]){

            ans += rest[3]/4;
            int t = rest[3]%4;
            if(t){
                ans++;
                cnt -= t*9;
                t = cnt/4 - 1;
                if(rest[2] > t) rest[2] -= t,cnt -= t*4;
                else {
                    cnt -= rest[2]*4;
                    rest[2] = 0;
                }
                // printf("%d %d %d\n",rest[1],cnt,t);
                if(rest[1] > cnt) rest[1] -= cnt;
                else rest[1] = 0;
            }
            cnt = 36;
        }
        //选二，然后选一
        if(rest[2]){

            ans += rest[2]/9;
            int t = rest[2]%9;
            if(t) ans++;{
                cnt -= t * 4;
                if(rest[1] > cnt) rest[1] -= cnt,cnt = 0;
                else cnt -= rest[1],rest[1] = 0;
            }
            cnt = 36;
        }
        //选一
        ans += rest[1]/36;
        if(rest[1]%36) ans++;
        printf("%d\n",ans);
    }
    return 0;
}