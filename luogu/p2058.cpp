#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
int nationcnt[300010]; //国籍中的人数
struct K{ //表示每个人的国籍和到港时间。
    int t;
    int nation;
};

queue<K> q;
int ans;
int main(){
    int n;
    scanf("%d", &n);
    struct K now;
    for(int i = 0; i < n; i++){
        int data, t, num;
        scanf("%d%d", &t, &num);
        while(q.size()){
            now = q.front();
            if(now.t + 86400 <= t){
                nationcnt[now.nation]--;
                if(nationcnt[now.nation] == 0) ans--; //目前没有该国人了
                q.pop();
                continue;
            }
            break;
        }
        for(int j = 0; j < num; j++){
            scanf("%d", &data);
            now.nation = data, now.t = t;
            q.push(now);
            nationcnt[data]++;
            if(nationcnt[data] == 1) ans++;  //第一次增加国旗(相对)
        }
        printf("%d\n", ans);
    }

    return 0;
}