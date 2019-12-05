/*
 * @Date: 2019-09-16 17:34:48
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-16 17:37:53
 */
#include<iostream>
#include<set>
using namespace std;

int main(){
    int N;
    cin >> N;
    set<int> s;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        s.insert(t);
    }
    set<int>::iterator it;
    cout << s.size() << endl;
    for(it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }
    return 0;
}