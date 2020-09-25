#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
map<int, int> bag[100010];
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int op, bagnum, grid, data;
        cin >> op;
        if(op == 1){
            cin >> bagnum >> grid >> data;
            bag[bagnum][grid] = data;
        } else {
            cin >> bagnum >> grid;
            cout << bag[bagnum][grid] << endl;
        }
    }
    return 0;
}