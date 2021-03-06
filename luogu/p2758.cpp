#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string a,b;
int dp[2010][2010];

int main(){
    memset(dp,0x3f,sizeof(dp));
    cin >> a >> b;
    for(int i = 0; i <= a.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= b.size(); i++) dp[0][i] = i;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
        }
    }
    cout << dp[a.size()][b.size()];
    return 0;
}