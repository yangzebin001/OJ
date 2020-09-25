#include<bits/stdc++.h>
using namespace std;
long a[200001];
long N,C,ans;
int main()
{
    cin>>N>>C;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+N+1);
    for(int i=1;i<=N;i++)
    {
        ans+=((upper_bound(a+1,a+N+1,a[i]+C)-a)-(lower_bound(a+1,a+N+1,a[i]+C)-a));
    }
    cout<<ans;
    return 0;
}