#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;

struct _member{
    string name;
    string position;
    int contribution;
    int grade;
    int order;
}member[120];


int n;
map<string , int> conidx;

int cmp(struct _member &a, struct _member &b){
     if(a.contribution != b.contribution) return a.contribution > b.contribution;
     return a.order < b.order;
}

int cmp2(struct _member &a, struct _member &b){
    if(conidx[a.position] != conidx[b.position]) return conidx[a.position] < conidx[b.position];
    if(a.grade != b.grade) return a.grade > b.grade;
    return a.order < b.order;
}


int pos[5] = {2,4,7,25,1000};
string posname[5] = {"HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
int idx = 0;
int nowcnt = 0;

int main(){
    for(int i = 0; i < 5; i++){
        conidx[posname[i]] = i;
    }

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> member[i].name >> member[i].position;
        cin >> member[i].contribution >> member[i].grade;
        member[i].order = i;
        if(i < 3){
            cout << member[i].name << " " << member[i].position << " " << member[i].grade << endl;
        }
    }

    sort(member+3, member+n, cmp);
    
    for(int i = 3; i < n; i++){
        if(nowcnt == pos[idx]){
            nowcnt = 0;
            idx++;
        }
        member[i].position = posname[idx];
        // cout << member[i].name << " " << posname[idx] << " " << member[i].grade << " " << member[i].contribution <<endl;
        nowcnt++;
    }

    sort(member+3, member+n, cmp2);
    nowcnt = 0; idx = 0;
    for(int i = 3; i < n; i++){
        if(nowcnt == pos[idx]){
            nowcnt = 0;
            idx++;
        }
        // member[i].position = posname[idx];
        cout << member[i].name << " " << member[i].position << " " << member[i].grade  <<endl;
        nowcnt++;
    }
    return 0;
}