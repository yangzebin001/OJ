/*
 * @Date: 2020-02-05 14:06:23
 * @LastEditors  : BeckoninGshy
 * @LastEditTime : 2020-02-05 14:26:36
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char top[11] = "- -- -----";
char tophalf[12][3] = {"||"," |"," |"," |","||","| ","| "," |","||","||"};
char middle[11] = "  ----- --";
char buttomhalf[12][3] = {"||"," |","| "," |"," |"," |","||"," |","||"," |"};
char buttom[11] = "- -- -- --";
int k;
string s;
int main(){
    cin >> k>> s;
    //打印上
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'0';
        if(i != 0) printf(" ");
        printf(" ");
        for(int j = 0; j < k; j++){
            printf("%c",top[c]);
        }
        printf(" ");
    }
    printf("\n");
    //打印上中
    for(int _ = 0; _ < k; _++){
        for(int i = 0; i < s.size(); i++){
            int c = s[i]-'0';
            if(i != 0) printf(" ");
            printf("%c",tophalf[c][0]);
            for(int j = 0; j < k; j++){
                printf(" ");
            }
            printf("%c",tophalf[c][1]);
        }
        printf("\n");
    }
    //打印中
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'0';
        if(i != 0) printf(" ");
        printf(" ");
        for(int j = 0; j < k; j++){
            printf("%c",middle[c]);
        }
        printf(" ");
    }
    printf("\n");
    //打印上中
    for(int _ = 0; _ < k; _++){
        for(int i = 0; i < s.size(); i++){
            int c = s[i]-'0';
            if(i != 0) printf(" ");
            printf("%c",buttomhalf[c][0]);
            for(int j = 0; j < k; j++){
                printf(" ");
            }
            printf("%c",buttomhalf[c][1]);
        }
        printf("\n");
    }
    //打印下
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'0';
        if(i != 0) printf(" ");
        printf(" ");
        for(int j = 0; j < k; j++){
            printf("%c",buttom[c]);
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}