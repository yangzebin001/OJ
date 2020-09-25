#include<iostream>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
multiset<int> s;
multiset<int>::iterator it;
int main(){
    s.insert(INT_MAX);
    s.insert(INT_MIN);

    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(a == 1){
            it = s.lower_bound(b);
            int j = 0;
            for(auto i = s.begin(); i != it; i++,j++);
            cout << j <<endl;
        }else if(a == 2){
            it = s.begin();
            while(b--) it++;
            cout << *it << endl;
        }else if(a == 3){
            cout << *(--s.lower_bound(b)) << endl;
        }else if(a == 4){
            cout << *(s.upper_bound(b)) << endl;
        }else{
            s.insert(b);
        }
    }
    return 0;
}