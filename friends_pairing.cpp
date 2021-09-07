#include<bits/stdc++.h>

using namespace std;

int func(int n, int*dp){ 

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    return dp[n];
}

int main(){
    int num_of_friends = 8;
    int dp[num_of_friends+1] = {0};
    cout<<func(num_of_friends, dp)<<endl;
    for(int i=0; i<num_of_friends; i++){
        cout<<dp[i]<<" ";
    }
}