#include<bits/stdc++.h>
using namespace std;


int main(){
    int m = 4, n = 4;
    int dp[m][n] = {};
    // int cost_grid[m][n] = { {1, 2, 3},
    //                         {4, 8, 2},
    //                         {1, 5, 3} };
    // calculate the cost of reaching (2,2) fron (0,0)
    // dp[i][j] means cost of reaching (i,j) from (0,0)
    // dp[0][0] = cost_grid[0][0];
    dp[0][0] = 1;
    
    for(int i=1; i<n; i++){
        int sum = 0;
        for(int k=0; k<=i-1; k++){
            sum += dp[k][0];
        }
    dp[i][0] = sum;
    }

    for(int j=1; j<n; j++){
        int sum = 0;
        for(int k=0; k<=j-1; k++){
            sum += dp[0][k];
        }
        dp[0][j] = sum;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){

            int sum=0;
            for(int k=0; k<=j-1; k++){
                sum += dp[i][k];
            }

            for(int k=0; k<=i-1; k++){
                sum += dp[k][j];
            }
            dp[i][j] = sum;
        }

        
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

   
}