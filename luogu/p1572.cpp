#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int up[1010];
int down[1010];
int uppos = 0, downpos = 0;
string s;
int flag = 1;

int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x%y);
}

int main(){
    cin >> s;
    if(s[0] != '-') s = '+' + s;
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-') flag = -1;
        else if(s[i] == '+') flag = 1;
        else{
            num = 0;
            while(i < s.size() && s[i] != '/') {
                num = num * 10 + (s[i]-'0');
                i++;
            }
            up[uppos++] = num*flag;
            flag = 1;
            num = 0;
            i++;
            while(i < s.size() && s[i] != '-' && s[i] != '+'){
                num = num * 10 + (s[i]-'0');
                i++;
            }
            down[downpos++] = num;
            num = 0;
            i--;
        }
    }
    int ans1 = 0, ans2 = 0;
    int a = up[0],b = down[0],c,d;
    for(int i = 1; i < uppos; i++){
        c = up[i], d = down[i];
        int lcm = b*d/gcd(b,d);
        ans2 = lcm;
        ans1 = a*(lcm/b) + c*(lcm/d);
        a = ans1/gcd(ans1,ans2);
        b = ans2/gcd(ans1,ans2);
    }
    ans1 = a, ans2 = b;
    if(ans2 < 0) ans1 *= -1, ans2 *= -1;
    if(ans2 == 1) printf("%d", ans1);
    else printf("%d/%d",ans1,ans2);
    return 0;
}