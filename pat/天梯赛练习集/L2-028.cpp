/*
 * @Date: 2019-11-19 21:14:35
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-11-20 17:29:15
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<map>
using namespace std;
const int MAXN = 1010;
vector<string> photo[MAXN];
double reman[MAXN],rewoman[MAXN];
int N,M;
map<int,string> sexM;

bool hasperson(string man,vector<string> &a){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == man) return true;
    }
    return false;
}

int sex(string a){
    if(a[0] == '-') return 1;
    return 0;
}
int ton(string a){
    int flag = sex(a);
    int ans = 0;
    for(int i = flag; i < a.size(); i++){
        ans *= 10;
        ans += (a[i]-'0');
    }
    return ans;
}

void calrelation(string man,vector<string> &a,int type){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == man) continue;
        if(sex(a[i]) == sex(man)) continue;
        if(type == 1){
            reman[ton(a[i])] += (1.0/a.size());
        }else{
            rewoman[ton(a[i])] += (1.0/a.size());
        }
    }
}

int main(){
    // freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    int k;
    char aa[50],bb[50];
    for(int i = 0; i < M; i++){
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%s",aa);
            photo[i].push_back(string(aa));
            sexM[ton(string(aa))] = string(aa);
        }
    }
    string man,woman;
    scanf("%s%s",aa,bb);
    man = string(aa);
    woman = string(bb);
    for(int i = 0; i < M; i++){
        if(hasperson(man,photo[i])){
            calrelation(man,photo[i],1);
        }
        if(hasperson(woman,photo[i])){
            calrelation(woman,photo[i],0);
        }
    }
    vector<string> remanmax,rewomanmax;
    double c = 0;
    for(int i = 0; i < N; i++){
        if(reman[i] > c){
            remanmax.clear();
            remanmax.push_back(sexM[i]);
            c = reman[i];
        }else if(reman[i] == c){
            remanmax.push_back(sexM[i]);
        }
    }
    c = 0;
    for(int i = 0; i < N; i++){
        if(rewoman[i] > c){
            rewomanmax.clear();
            rewomanmax.push_back(sexM[i]);
            c = rewoman[i];
        }else if(rewoman[i] == c){
            rewomanmax.push_back(sexM[i]);
        }
    }
    //两者都在对方的最亲密关系内，或者两者根本就没有出现。
    if((hasperson(woman,remanmax) && hasperson(man,rewomanmax))||(remanmax.size() == N && rewomanmax.size() == N)){
        printf("%s %s\n",man.c_str(),woman.c_str());
    }else{
        for(int i = 0; i < remanmax.size(); i++){
            printf("%s %s\n",man.c_str(),remanmax[i].c_str());
        }
        for(int i = 0; i < rewomanmax.size(); i++){
            printf("%s %s\n",woman.c_str(),rewomanmax[i].c_str());
        }
    }
    return 0;
}
