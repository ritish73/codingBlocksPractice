#include<bits/stdc++.h>
using namespace std;
// const int N = 6;
// int optimal_game_strategy(int* a, int n,int dp[N][N]){ 


   

//     return dp[0][n-1];
// }


int main(){

    int n = 6;

    int a[n] = {20, 30, 2, 2, 2, 10};
    int dp[n][n] = {};

   



     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(i>j) {dp[i][j] = 0;}
            if(i==j){
                dp[i][j] = a[i];
            }
            if(j==i+1){
                dp[i][j] = max(a[i],a[j]);
            }
            
        }
    }


   


    for(int L=2; L<=n-1; L++){
        for(int i=0; i<n; i++){
            int j = i + L;

            if(i>n-1 || j>n-1) continue;
            cout<<" i , j pair is ( "<<i<<" , "<<j<<" ) for L : "<<L<<endl;
            int aa = dp[i+2][j];
            int b = dp[i+1][j-1];
            int c = dp[i][j-2];
            cout<<aa<<b<<c<<endl;
            int op1 = a[i] + min(aa,b);
            int op2 = a[j] + min(b,c);
            dp[i][j] = max(op1,op2);
        }
    }






    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
         cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }






}