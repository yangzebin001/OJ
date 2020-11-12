#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
 
using namespace std;
 
string s;
map<char, int> M;
// ABT 出现的组合情况
char per[6][3] = {
  {'A', 'B', 'T'},
  {'A', 'T', 'B'},
  {'B', 'A', 'T'},
  {'B', 'T', 'A'},
  {'T', 'A', 'B'},
  {'T', 'B', 'A'},
};
 
int minimumSwapCount (char com[]) {
  map<char, int> m1, m2, m3;
  char c1 = com[0], c2 = com[1], c3 = com[2];
  int l = 0;
  int r = M[c1];
  int res = 0;
  for (int i = l; i < r; i++)
    m1[s[i]]++;
   
  l = r;
  r = l + M[c2];
  for (int i = l; i < r; i++)
    m2[s[i]]++;
   
  l = r;
  r = s.length();
  for (int i = l; i < r; i++)
    m3[s[i]]++;
   
  // printf("A = %d, B = %d, T = %d\n", m1['A'], m1['B'], m1['T']);
  // printf("A = %d, B = %d, T = %d\n", m2['A'], m2['B'], m2['T']);
  // printf("A = %d, B = %d, T = %d\n", m3['A'], m3['B'], m3['T']);
  // cout << endl;
 
  // m1 只能有 c1 存在，c2 和 c3 都需要与 m2, m3 交换
  while (m1[c2]) {
    if (m2[c1]) {
      m1[c1]++;
      m2[c1]--;
      m1[c2]--;
      m2[c2]++;
      res++;
    } else if (m3[c1]) {
      m1[c1]++;
      m3[c1]--;
      m1[c2]--;
      m3[c2]++;
      res++;
    }
  }
  while (m1[c3]) {
    if (m2[c1]) {
      m1[c1]++;
      m2[c1]--;
      m1[c3]--;
      m2[c3]++;
      res++;
    } else if (m3[c1]) {
      m1[c1]++;
      m3[c1]--;
      m1[c3]--;
      m3[c3]++;
      res++;
    }
  }
 
  // m1 经过与 m2 和 m3 的交换后，m1 里只会保留 c1
  // m2 里可能还有 c2 和 c3 的值，与 m3 交换
  while (m2[c3]) {
    if (m3[c2]) {
      m2[c2]++;
      m3[c2]--;
      m2[c3]--;
      m3[c3]++;
      res++;
    }
  }
 
  // 经过上面的循环，m1 内只有 c1，m2 内只有 c2，由此 m3 内只会有 c3
  // 返回本次组合的交换次数
  return res;
}
 
int main () {
  cin >> s;
 
  // ifstream infile;
  // infile.open("in.txt");
  // infile >> s;
   
  int n = s.length(), ans = 1 << 21;
 
  // 求出输入字符串中，A、B 和 T 的出现次数
  for (int i = 0; i < n; i++)
    M[s[i]]++;
   
  // 求每种组合最小的交换次数
  for (int i = 0; i < 6; i++)
    ans = min(ans, minimumSwapCount(per[i]));
 
  cout << ans << endl;
 
  return 0;
}