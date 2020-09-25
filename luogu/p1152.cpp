#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;
set<int> vis;
int main(){
    int n,a,b;
    cin >> n >> a;
    for(int i = 1; i < n; i++){
        cin >> b;
        if(i > 0){
            int c = abs(b - a);
            if(c >= 1 && c < n) vis.insert(c);
        }
        a = b;
    }
    if(vis.size() != n-1){
        printf("Not jolly\n");
    }else{
        printf("Jolly\n");
    }

    return 0;
}