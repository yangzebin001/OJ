#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;
char a[110], b[110]; //b数组存放与a对应位置相反的括号序列，使其相同位置的两个括号可以匹配
int q[110], top;
int main(){
    scanf("%s", a);
    int n = strlen(a);
    for(int i = 0; i < n; i++){
        if(a[i] == '('){
            q[++top] = i;
            b[i] = ')';
        }else if(a[i] == '['){
            q[++top] = i;
            b[i] = ']';
        }else if(a[i] == ')' || a[i] == ']'){
            //先检查栈顶是否与当前括号是否匹配
            if(!top || b[q[top]] != a[i]){  //不与栈顶的括号匹配，添加相应左括号 
                a[i] == ')' ? b[i] = '(' : b[i] = '[';
            }else{
                b[q[top--]] = ' ';  //匹配，置空
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(b[i] == '(' || b[i] == '[') printf("%c", b[i]);
        printf("%c", a[i]);
        if(b[i] == ')' || b[i] == ']') printf("%c", b[i]);
    }
    return 0;
}