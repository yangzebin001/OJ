#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
set<PII> segs;
set<PII>::iterator it1,it2;
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        it1 = segs.lower_bound({x,INT_MIN});
        if(it1 != segs.end() && it1->second <= x) x = it1->first+1;
        cout << x << ' ';
        segs.insert({x,x});
        if(it1 != segs.begin()) it1--;
        for(int i = 0; i < 2 && it1 != segs.end(); i++){
            it2 = it1;
            it2++;
            if(it2 != segs.end() && it1->first+1 == it2->second){
                int l = it1->second, r = it2->first;
                segs.insert({r,l});
                segs.erase(it1);
                segs.erase(it2);
                it1 = segs.find({r,l});
            } else {
                it1 = it2;
            }
        }

    }
    return 0;
}