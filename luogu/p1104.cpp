#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct s{
    string name;
    int birthday;
    int order;
}student[200];

int cmp(struct s &a, struct s &b){
    if(a.birthday != b.birthday) return a.birthday < b.birthday;
    return a.order > b.order;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> student[i].name;
        int y,m,d;
        cin >> y >> m >> d;
        student[i].birthday = y*10000 + m * 100 + d;
        student[i].order = i;
    }
    sort(student, student+n, cmp);
    for(int i = 0; i < n; i++){
        cout << student[i].name << endl;
    }
    return 0;
}