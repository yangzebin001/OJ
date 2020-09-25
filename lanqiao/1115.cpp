#include<iostream>
#include<cstdio>

using namespace std;
int n;
char map[50][50];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        for(int j = 0; j < a; j++){
            for(int k = 0; k < a; k++){
                if(j == k || j+k == a-1){
                    map[j][k] = 'X';
                }else{
                    map[j][k] = ' ';
                }
            }
        }
        for(int j = 0; j < b; j++){
            if(j == 0){
                for(int k = 0; k < a; k++){
                    printf("%c", map[0][k]);
                }
                printf("\n");
            }
            for(int k = 1; k < a; k++){
                for(int p = 0; p < a; p++){
                    printf("%c", map[k][p]);

                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}