/*
 * @Date: 2020-01-14 12:29:47
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 12:45:03
 */
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct stu{
    string name;
    int avgscore,disscore,papernum,award = 0;
    string isweststu,iscaptial;
}Stu[105];
void cal(stu &a){
    if(a.avgscore > 80 && a.papernum > 0) a.award += 8000;
    if(a.avgscore > 85 && a.disscore > 80) a.award += 4000;
    if(a.avgscore > 90 ) a.award += 2000;
    if(a.avgscore > 85 && a.isweststu == "Y") a.award += 1000;
    if(a.disscore > 80 && a.iscaptial == "Y") a.award += 850;
}
string maxawardname;
int maxawardscore = -1,sumaward = 0;
int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        cin >> Stu[i].name >> Stu[i].avgscore >> Stu[i].disscore >>Stu[i].iscaptial >>Stu[i].isweststu >>Stu[i].papernum;
        cal(Stu[i]);
        if(Stu[i].award > maxawardscore){
            maxawardscore = Stu[i].award;
            maxawardname = Stu[i].name;
        }
        sumaward += Stu[i].award;
    }
    cout  << maxawardname << endl << maxawardscore << endl << sumaward << endl;
    return 0;
}