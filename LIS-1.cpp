#include<bits/stdc++.h>
using namespace std;

int lis1(int *arr, int size,int* dp){
    dp[0] = 1;
    // conditions for j, j<i and arr[j] < arr[i]
    for(int i=1; i<size; i++){
        int maximum = INT_MIN;
        for(int j=i-1; j>=0; j--){
            if(j<i && arr[j] < arr[i]){
                maximum = max(maximum,dp[j]);
            }
        }
        dp[i] = maximum + 1;
    }
    return dp[size-1];
    
}

int main(){
    int arr[] = {1,5,2,3,4,9,6,10};
    int dp[8] = {0};
    cout<<lis1(arr,8,dp)<<endl;
    for(int i=0;i<8;i++){
        cout<<dp[i]<<" ";
    }
}