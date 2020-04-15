/*
 * @Date: 2020-03-25 19:38:42
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2020-03-25 19:43:03
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

typedef long long LL;
using namespace std;

int N;
const int MOD = 10000;
int mem[1001][1000];

int dfs(int pre, int cur) {
    if (cur <= 0) return 0;
    if (mem[pre][cur] != 0) return mem[pre][cur];
    return mem[pre][cur] = (1 + dfs(pre, cur - 1) + dfs(cur, abs(pre - cur) - 1)) % MOD;
}

void work() {
    cin >> N;
    cout << dfs(N, N) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a = clock();
    work();
    int b = clock();
    clog << (b - a) << endl;
    return 0;
}
