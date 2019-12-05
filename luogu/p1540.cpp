#include<iostream>
#include<cstdio>
const int MAXN = 2000;
using namespace std;

int q[MAXN];
int l = 0,r = 0;
bool find(int a){

    for(int i = l; i < r; i++){
        if(q[i] == a) return true;
    }
    return false;
}


int main(){
    freopen("in.txt","r",stdin);
    int M,N;
    scanf("%d%d",&M,&N);
    int cont = 0;
    for(int i = 0; i < N; i++){
        int a;
        scanf("%d",&a);
        if(find(a)) continue;
        if(r-l < M) q[r++] = a;
        else if( r-l == M){
            q[r++] = a;
            l++;
        }
        cont++;
    }
    printf("%d",cont);
    return 0;
}
