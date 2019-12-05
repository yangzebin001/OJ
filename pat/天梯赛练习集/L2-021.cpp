/*
 * @Date: 2019-11-20 17:34:05
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-20 17:45:11
 */
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN = 110;
struct n{
    string name;
    map<int,int> tags;
}S[MAXN];

bool cmp(n &a, n &b){
    if(a.tags.size() == b.tags.size()){

        double a1 = 0,b1 = 0;
        map<int,int>::iterator it;
        for(it = a.tags.begin(); it != a.tags.end(); it++){
            a1 += it->second;
        }
        a1 /= a.tags.size();
        for(it = b.tags.begin(); it != b.tags.end(); it++){
            b1 += it->second;
        }
        b1 /= b.tags.size();
        return a1 < b1;
    }
    return a.tags.size() > b.tags.size();
}
int main(){
    freopen("in.txt","r",stdin);
    int N;
    int k,a;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        char aa[50];
        scanf("%s",aa);
        S[i].name = string(aa);
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%d",&a);
            S[i].tags[a]++;
        }
    }
    sort(S,S+N,cmp);
    int i;
    for(i = 0; i < 3 && i < N; i++){
        if(i != 0) printf(" ");
        printf("%s",S[i].name.c_str());
    }
    while(i < 3){
        if(i != 0) printf(" ");
        printf("-");
        i++;
    }
    return 0;
}