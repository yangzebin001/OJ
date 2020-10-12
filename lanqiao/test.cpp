#include <bits/stdc++.h>
using namespace std;
 
int get() {
     char line[100] = {};
     cin.getline(line, 100);
     int h1, m1, s1, h2, m2, s2, d=0;
     if(strlen(line) == 17)
         sscanf(line, "%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
     else 
         sscanf(line, "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
     return (d*24+h2-h1)*3600 + (m2-m1) * 60 + s2-s1;
 }
 
 int main() {
     int T;
     cin >> T; getchar();
     while(T--) {
         int time1 = get();
         int time2 = get();
         int t = (time2+time1) / 2;
         printf("%d\n",t);
         printf("%02d:%02d:%02d\n", t/3600, t/60%60, t%60);
     }
     return 0;
}