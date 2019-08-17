#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

void convert(string a, int &inum,int &num){
    int x = 0;
    int flag = 1;
    bool innum = false;
    for(int i = 0;i < a.size(); i++){
        if(a[i] >= '0' && a[i] <= '9'){
            innum = true;
            x *= 10; x += a[i]-'0';
        }else if(a[i] == '+' || a[i] == '-'){
            if(innum){num += flag*x;}
            flag = a[i] == '+' ? 1 : -1;
            innum = false;
            x = 0;
        }else if(a[i] >= 'a' && a[i] <= 'z'){
            if(innum)inum+=x*flag;
            else inum+=flag;
            flag = 1;
            x = 0;
            innum = false;
        }
    }
    if(innum){num += flag*x;}
}

int main(){
    string a;
    string c = "";
    getline(cin,a);
    int flag = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < 'a' || a[i] > 'z'){
            if(flag == 1) break;
        }
        if(a[i] >= 'a' && a[i] <= 'z'){
            flag = 1;
            c+=a[i];
        }
    }
    string x = a.substr(0,a.find('='));
    string y = a.substr(a.find('=')+1);
    int ax = 0, ay = 0,bx = 0,by = 0;
    convert(x,ax,ay);
    convert(y,bx,by);
    cout<<ay << " " << ax << endl;
    cout << by << " " << bx << endl;
    int yy = ay-by;
    int xx = bx-ax;
    printf("%s=%.3lf",c.c_str(),yy*1.0/xx);
    return 0;
}