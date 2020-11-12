#include<bits/stdc++.h>

using namespace std;
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
int ans = 0;
set<string> vis;
long long nums[10];
long long nums2[10];
void dfs(int idx, int k){
    if(idx == 10){
        for(int i = 0; i < k; i++){
            nums2[i] = nums[i];
        }
        sort(nums2,nums2+k);
        string s = "";
        for(int i = 0; i < k; i++){
            s += to_string(nums2[i]) + ",";
        }
        if(!vis.count(s)) {
            vis.insert(s);
            // cout << s << endl;
            ans++;
        }
        return;
    }
    if(arr[idx] == 0){
        nums[k] = 0;    
        dfs(idx+1,k+1);
    }
    else{
        long long a = 0;
        for(int i = idx; i < 10; i++){
            a = a*10+arr[i];
            double ss = sqrt(a);
            if(ss == (int)ss){
                nums[k] = a;
                dfs(i+1,k+1);
            }
        }

    }
}

int main(){

    do{
        dfs(0,0);
    }while(next_permutation(arr,arr+10));
    cout << ans;
    return 0;
}