#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 100000+5;

int d[MAXN];
int vis[MAXN];
int N;

int cont = 0;
void work(int i){
    int k = d[i];
    while(!vis[k]){
        vis[k] = 1;
        k = d[k];
        cont++;
    }
    cont++;
}

bool isSorted(){
	for(int i = 1; i < N; i++){
		if(d[i] < d[i-1]) return false;
	}
	return true;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    int zero = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&d[i]);
        if(i == d[i]) vis[i] = 1;
        if(d[i] == 0) zero = i;
    }
    if(isSorted()){
    	printf("%d", cont);
    	return 0;
	}
    
    if(!zero) cont+=2;
    for(int i = 0; i < N; i++){
    	if(!vis[i]){
        	work(i);
		}
        
    }
    printf("%d",cont-2);
    return 0;
}
