#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int N;
vector<int> c(10);
void dfs(int n, int t){
    if(n == 0){
        if(c[N] == 1) return;
        int f = 0;
        for(int i = 1; i < 10; i++){
            int j = 0;
            while(j < c[i]){
                if(f == 1) cout << "+";
                else {
                    f = 1;
                }
                cout << i;
                j++;
            }
        }
        cout << endl;
        return;
    }
    for(int i = t; i <= n; i++){
        c[i]++;
        dfs(n-i, i);
        c[i]--;
    }
}

int main(){
    cin >> N;
    dfs(N, 1);
    return 0;
}