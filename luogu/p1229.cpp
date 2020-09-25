#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string a,b;
int ans = 1;
int main(){
    cin >> a >> b;
    //只有一个儿子的节点才会在知道前序后序的情况下有不同的中序遍历
    //即前序为AB 后序为BA 根据乘法原理 *2
    for(int i = 0; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j] && a[i+1] == b[j-1]){
                ans <<= 1;
            }
        }
    }
    cout << ans; 
    return 0;
}