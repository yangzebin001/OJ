/*
 * @Date: 2019-08-25 15:44:41
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-08-26 08:42:20
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int> > ans;
int num; //目标数
int npath; //最优路径
int curNum; //当前数，dfs中间值
int cntNum; //当前数的出现次数。

/*
将结果数组中的各值相加
*/
int getNum(vector<vector<int> > t, int n){
    int ans = 0;
    int cont = 0;
    for(int j = 0; j < t.size(); j++){
        int c = 0;
        cont += t[j].size();
        for(int k = 0; k < t[j].size(); k++)
        {
            c = c*10 + t[j][k];
        }    
        ans +=c;
    }
    return ans;
}
/*
i:当前位置
n：总长度
path：记录每次分割长度
s：总数据
t：结果数组。
*/
void dfs(int i,int n,int path,char s[],vector<vector<int> > t){
    int tt = getNum(t,n);
    //如果过程中已经比当前数大了，直接剪掉
    if(tt > num) return;
    
    if(i == n){
        //在当前一轮结束时更新离目标数最近并小于目标数的值、次数与路径。
        if(curNum < tt){
            cntNum = 1;
            curNum = tt;
            npath = path;
        }else if(curNum == tt){
            cntNum++;
        }
        return;
    }
    /*
    dfs核心：
    输入：1234
    生成下列排列
    1 2 3 4 
    1 2 34 
    1 23 4 
    1 234 
    12 3 4 
    12 34 
    123 4 
    1234
    */
    vector<int> a;
    for(int j = i; j < n; j++){
        a.push_back(s[j]-'0');
        t.push_back(a);
        dfs(j+1,n,path*10+j-i+1,s,t);
        t.pop_back();
    }
    
}

//根据path输出各个数。
void show(char s[],int path){
    vector<int> a;
    while(path){
        a.push_back(path%10);
        path/=10;
    }
    reverse(a.begin(),a.end());
    int j = 0;
    for(int i = 0; i < a.size(); i++){
        printf(" ");
        for(int k = 0; k < a[i]; k++){
            printf("%c",s[j++]);
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a;
    char s[1000];
    while(scanf("%d%s",&a,s) && a){
        vector<vector<int> > t;
        num = a;
        curNum = 0;
        cntNum = 0;

        int sum = 0;
        for(int i = 0; i < strlen(s); i++){
            sum += s[i]-'0';
        }
        //给定数的每一位相加都比目标数大
        if(sum > a){
            printf("error\n");
        }else{
            dfs(0,strlen(s),0,s,t);
            if(cntNum > 1){
                printf("rejected\n");
            }else{
                printf("%d",curNum);
                show(s,npath);
                printf("\n");
            }
        } 
    }
    return 0;
}