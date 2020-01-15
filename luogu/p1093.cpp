/*
 * @Date: 2020-01-14 12:47:14
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-01-14 12:53:48
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
struct stu{
    int num,chinese,math,english,sum;
}Stu[305];
int cmp(stu &a, stu &b){
    if(a.sum == b.sum){
        if(a.chinese == b.chinese) return a.num < b.num;
        return a.chinese > b.chinese;
    }
    return a.sum > b.sum;
}
int main(){
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Stu[i].chinese >> Stu[i].math >>Stu[i].english;
        Stu[i].sum = Stu[i].chinese + Stu[i].math + Stu[i].english;
        Stu[i].num = i+1;
    }
    sort(Stu,Stu+n,cmp);
    
    for(int i = 0; i < 5 && i < n; i++){
        cout << Stu[i].num <<" " << Stu[i].sum << endl;
    }
    return 0;
}