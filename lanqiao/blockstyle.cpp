#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int, int> Hash;
int ans = 0, graph[3][10];

bool check() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 9; j++)
            if ((graph[i][j] + graph[i][j + 1] + graph[i + 1][j] + graph[i + 1][j + 1]) % 4 == 0)
                return false;
    return true;
}

void dfs(int x, int y) {
    if (graph[x][y] == -1) {
        //横向铺设
        if (y < 9 && graph[x][y + 1] == -1) {
            for (int i = 0; i < 2; i++) {
                graph[x][y] = graph[x][y + 1] = i;
                dfs(x, y + 1);
                graph[x][y] = graph[x][y + 1] = -1;
            }
        }
        //纵向铺设
        if (x < 2 && graph[x + 1][y] == -1) {
            for (int i = 0; i < 2; i++) {
                graph[x][y] = graph[x + 1][y] = i;
                if (y == 9) dfs(x + 1, 0);
                else dfs(x, y + 1);
                graph[x][y] = graph[x + 1][y] = -1;
            }
        }
    } else {
        if (x == 2 && y == 9) {
            if (check()) {
                int ret = 0;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 10; j++)
                        ret = ret * 2 + graph[i][j];
                Hash[ret]++;
                if (Hash[ret] == 1)
                    ans++;
            }
            return;
        }
        if (y == 9) dfs(x + 1, 0);
        else dfs(x, y + 1);
    }
}

int main() {
    memset(graph, -1, sizeof(graph));
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}