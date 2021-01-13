#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n;

int main(){
    cin >> n;
    if(n >= 90){
        cout << "4.0" << endl;
        return 0;
    }else if(n >= 60){
        double score = 4.0;
        int t = 90-n;
        score = score - (t*0.1);
        printf("%.1f",score);
        return 0;
    }else{
        int s = (int)(sqrt(1.0*n) * 10);
        if(s >= 90){
            cout << "4.0" << endl;
            return 0;
        }else if(s >= 60){
            double score = 4.0;
            int t = 90-s;
            score = score - (t*0.1);
            printf("%.1f",score);
            return 0;
        }else{
            cout << "0.0" << endl;
            return 0;
        }
    }
    return 0;
}