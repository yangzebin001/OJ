#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int record[16][16];

void flip(int i, int j){
    for(int k = 0; k < 4; k++){
        record[i][k]++;
        record[k][j]++;
    }
    record[i][j]--;
}


int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            char c;
            scanf("%c",&c);
            if(c == '+') flip(i,j);
        }
        getchar();
    }
    
    int cnt = 0;
    for(int i = 0; i <4; i++){
        for(int j = 0; j < 4; j++){
            if(record[i][j]&1) cnt++;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(record[i][j]&1){
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}