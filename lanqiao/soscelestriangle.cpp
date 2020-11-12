#include<bits/stdc++.h>

using namespace std;
int pos[2010], idx;

int field[310][310];

int main(){
    memset(field, -1, sizeof(field));
    for(int i = 1; idx < 2010; i++){
        int c = i;
        int cc[10];
        int ccc = 0;
        while(c){
            cc[ccc++] = c%10;
            c /= 10;
        }
        for(int j = ccc-1; j >= 0; j--){
            pos[idx++] = cc[j];
        }
    }
    int n;
    cin >> n;
    idx = 0;
    field[1][n] = 1;
    int x = 2, y = n-1;
    for(int i = 0; i < n-2; i++){
        field[x][y] = pos[++idx];
        x++, y--;
    }
    for(int i = 1; i <= 2*n-1; i++){
        field[n][i] = pos[++idx];
    }
    x = n-1, y = 2*n-2;
    for(int i = 0; i < n-2; i++){
        field[x][y] = pos[++idx];
        x--, y--;
    }
    for(int i = 1; i <= n; i++){
        if(field[1][i] == -1) cout << '.';
        else cout << field[1][i];
    }
    cout << endl;
    for(int i = 2; i < n; i++){
        int c = 0;
        for(int j = 1; j <= 2*n-1; j++){
            if(field[i][j] == -1) cout << '.';
            else cout << field[i][j];
            if(field[i][j] >= 0)c++;
            if(c == 2) break;
        }
        cout << endl;
    }
    for(int j = 1; j <= 2*n-1; j++){
            cout << field[n][j];
        }
        cout << endl;
    return 0;
}