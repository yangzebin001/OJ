/*
 * @Date: 2019-09-20 21:29:25
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-09-20 21:34:43
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int num,b;
int main(){
    scanf("%d%d",&num,&b);
    vector<int> v1,v2;
    while(num){
        v1.push_back(num%b);
        num /= b;
    }
    v2 = v1;
    reverse(v2.begin(),v2.end());
    if(v1 == v2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    for(int i = 0; i < v2.size(); i++){
        if(i != 0) printf(" ");
        printf("%d",v2[i]);
    }
    return 0;
}