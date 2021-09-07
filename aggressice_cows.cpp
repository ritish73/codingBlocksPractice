#include <iostream>
#include<algorithm>
using namespace std;

bool canPlaceAllCowsWithSeparation_m(int* a, int n, int c, int m){

    int last_cow = a[0];
    int count = 1; // place first cow at stall one
    for(int i=1; i<n; i++){
        if(a[i] - last_cow >= m){
            last_cow = a[i];
            count++;
            if(count == c) return true; // all cows are placed
        }
    }

    return false;
}

int aggrcows(int* a, int n, int c){
    // sort the array first
    sort(a,a+n);
    int s = 0;
    int e = a[n-1] - a[0];  // here we take the maximum separation possible
    int ans = 0; // stores maximum separation for cows not to be aggressive
    while(s<=e){
        int m = (s+e)/2;
        bool canplace = canPlaceAllCowsWithSeparation_m(a,n,c,m); // tells whether all cows can be placed with separation m
        if(canplace){
            ans = m;
            s = m + 1; // coz now we want to check whether all cows can be placed at distance  > m , coz we want max distance
        } else {
            // now reduce the search space as we could not accomodate all cows at a separation of m
            e = m - 1;
        }
    }
    return ans;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int j=0; j<n; j++){
            cin>>a[j];
        }
        cout<<aggrcows(a, n, c)<<endl;
    }
	return 0;
}
