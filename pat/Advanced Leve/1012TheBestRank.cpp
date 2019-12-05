/*
 * @Date: 2019-10-21 15:03:28
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-21 15:53:17
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<vector>

using namespace std;
const int MAXN = 2010;
struct node{
    string ID;
    int C,M,E,A;
    int ind[4];
};
int N,M;
node stu[MAXN];
map<string, int> m;

void insert(vector<pair<int,int> > &ans,int x){
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    int q = 1;
    stu[ans[0].second].ind[x] = q;
    for(int i = 1; i < N; i++){
        if(ans[i-1].first != ans[i].first) {
            q = i+1;
        }
        stu[ans[i].second].ind[x] = q;
    }
}
void getMax(int x){
    int c = 1000;
    int q = -1;
    for(int i = 0; i < 4; i++){
        if(stu[x].ind[i] < c){
            c = stu[x].ind[i];
            q = i;
        }
    }
    cout << c << " ";
    if(q == 0) cout << "A" << endl;
    if(q == 1) cout << "C" << endl;
    if(q == 2) cout << "M" << endl;
    if(q == 3) cout << "E" << endl;
}
int main(){
    freopen("in.txt","r",stdin);
    cin >> N >> M;
    if(N == 0) return 0;
    for(int i = 0; i < N; i++){
        cin >> stu[i].ID >> stu[i].C >> stu[i].M >> stu[i].E;
        stu[i].A = (double(stu[i].C) + stu[i].M + stu[i].E)/3+ 0.5;
        m[stu[i].ID] = i;
    }
    vector<pair<int,int> > forsort;
    for(int i = 0; i < N; i++){
        forsort.push_back(make_pair(stu[i].A,i));
    } 
    insert(forsort,0);
    forsort.clear();
    for(int i = 0; i < N; i++){
        forsort.push_back(make_pair(stu[i].C,i));
    } 
    insert(forsort,1);
    forsort.clear();
    for(int i = 0; i < N; i++){
        forsort.push_back(make_pair(stu[i].M,i));
    } 
    insert(forsort,2);
    forsort.clear();
    for(int i = 0; i < N; i++){
        forsort.push_back(make_pair(stu[i].E,i));
    } 
    insert(forsort,3);
    forsort.clear();
    for(int i = 0; i < M; i++){
        string w;
        cin >> w;
        if(m.find(w) == m.end()){
            cout << "N/A" << endl;
            continue;
        }
        getMax(m[w]);
    }
    return 0;
}