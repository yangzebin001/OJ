#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
int n;
inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
unordered_map<int, int> s;
int arr[50010];
int main(){
    n = read();
    while(n--){
        s.clear();
        int t, a;
        t = read();

        for(int i = 0 ; i < t; i++){
            arr[i] = read();
        }
        for(int i = 0; i < t; i++){
            if(!s.count(arr[i])){
                printf("%d ", arr[i]);
                s[arr[i]] = 1;
            }
        }
        printf("\n");
    }
    return 0;
}