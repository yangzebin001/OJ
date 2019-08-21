#include<iostream>
#include<vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

int main(){
    vector<int> a({1,2,3});
    vector<int> b({9,5,9});
    vector<int> ans = add(a,b);
    for(int i = 0; i < ans.size(); i++){
        printf("%d ",ans[i]);
    }
    return 0;
}