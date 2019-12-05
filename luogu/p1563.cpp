/*
 * @Date: 2019-09-09 16:19:59
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-09 16:36:57
 */
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 100010;

struct preson{
    string name;
    int dir;
}P[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> P[i].dir >> P[i].name;
        // cout << P[i].dir << " " << P[i].name << endl;
    }
    int k = 0;
    int d = 0,step = 0;
    // 0 圈外，左边， 1 圈内，右边
    //又因为读入是逆时针，所以全部反一下
    for(int i = 0; i < m; i++){
        cin >> d >> step;
        //右边
        if(d == 1){
            //圈内 ++；
            if(P[k].dir == 0){
                k = (k + step) % n;
            }else{
                k = (k-step+n) % n;
            }
        }else{
            if(P[k].dir == 1){
                k = (k + step) % n;
            }else{
                k = (k-step+n) % n;
            }
        }
    }
    cout << P[k].name << endl;
    return 0;
}