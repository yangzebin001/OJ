#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int num[1000];

int main(){
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        char ch;
        int ans = 0x3f3f3f3f;
        int k = 0;
        while(1)
        {
            scanf("%d%c",&num[k++],&ch);//输入数据
            if (ch=='\n')//回车停止输入
                break;
        }
        if(k == 2){
            printf("%d\n",abs(num[0]-num[1]));
            continue;
        }
        int mid = k/2;
        do{
            int l = num[0];
            int r = num[mid];
            //不能以零开头
            if(l == 0 || r == 0) continue;
            for(int j = 1; j < mid; j++){ l*= 10; l+= num[j];}
            for(int j = mid+1; j < k; j++){ r*= 10; r+= num[j];}
            ans = min(ans,abs(r-l));
        }while(next_permutation(num,num+k));
        printf("%d\n",ans);
    }

    return 0;
}