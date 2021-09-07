#include<bits/stdc++.h>

using namespace std;

int func(int nodes, int*dp){ 
    // reccurence relation : f(n) = all i sum(f(i-1)*f(n-i))
    dp[0] = 1;
    dp[1] = 1;
    for(int n=2; n<=nodes; n++){
        dp[n]=0;
        for(int i=1;i<=n;i++){
            dp[n] += dp[i-1]*dp[n-i];
        }
    }
    return dp[nodes];
}


int main(){
    int nodes = 5;
    int dp[nodes+1] = {0};
    cout<<func(nodes, dp)<<endl;

    for(int i=0; i<=nodes; i++){
        cout<<dp[i]<<" ";
    }
}