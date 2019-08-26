#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int MAXN = 20010;

int table[MAXN];
int backup[MAXN];
int T;
int flag = 0;
int M,N;
int isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return n != 1;
}

int nextPrime(int n){
    if(n <= 1) return 2;
    while(!isPrime(n)) n++;
    return n;
}

void insert(int n){
    set<int> s;
    int qnum = 0;
    int cur = n % T;
    int cc = cur;
    while(table[cc] != -1){
        qnum++;
        cc = cur + (qnum*qnum);
        cc = cc % T;
        if(qnum >= M){
            
            if(flag){
                printf(" ");
            }else{
                flag = 1;
            }
            printf("-");
            return;
        }
        // s.insert(cur);
    }

    table[cc] = 1;
    if(flag){
        printf(" ");
    }else{
        flag = 1;
    }
    printf("%d",cc);
    return;
}

int main(){
    memset(table,-1,sizeof(table));
    cin >> M >> N;
    T = nextPrime(M);
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        insert(a);
    }
    return 0;
}