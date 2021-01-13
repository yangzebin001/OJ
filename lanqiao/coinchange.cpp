#include<bits/stdc++.h>

using namespace std;

int main(){
    int ans = INT_MAX;
    for(int i = 1; i + 20*i < 200; i++){
        if((200 - i-20*i)%5==0){
            ans = min(ans, i+10*i+(200 - i-20*i)/5);
        }
    }
    cout << ans;
    return 0;
}