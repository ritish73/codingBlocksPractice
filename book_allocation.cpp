#include<iostream>
#include<algorithm>
using namespace std;

int sumAllElements(int *a, int n){
    int s = 0;
    for(int i=0; i<n; i++){
        s += a[i];
    }
    return s;
}

bool isPossible(int *a, int n, int k, int m){
    int i=0;
    int count = 0;
    
    
}


int allocateBooks(int *a, int n, int k){

    if(k>n) return -1;
    sort(a,a+n);
    int maximum = *max_element(a,a+n);

    int s = maximum;
    int e = sumAllElements(a,n);
    int ans = -1;
    while(s<=e){
        int m = (s+e)/2;
        bool possible = isPossible(a,n,k,m);
        // cout<<possible<<endl;
        if(possible){
            ans = m;
            e = m-1;
        } else{
            s = m+1;
        }
    }

    // cout<<maximum<<endl;
    return ans;
}

int main(){
    int a[9] = {10,20,40,30,90,70,100,800,200};
    int n = 9;
    int k = 2;
    cout<<allocateBooks(a,n,k);
}