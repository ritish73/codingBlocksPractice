#include<bits/stdc++.h>
using namespace std;


int main(){
    int n =3;
    int dp[n][n] = {};
    int cost_grid[n][n] = { {1, 2, 3},
                            {4, 8, 2},
                            {1, 5, 3} };
    // calculate the cost of reaching (2,2) fron (0,0)
    // dp[i][j] means cost of reaching (i,j) from (0,0)
    dp[0][0] = cost_grid[0][0];

    for(int i=1; i<n; i++){
        dp[i][0] = cost_grid[i][0] + dp[i-1][0];
    }
    for(int j=1; j<n; j++){
        dp[0][j] = cost_grid[0][j] + dp[0][j-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = cost_grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

   
}