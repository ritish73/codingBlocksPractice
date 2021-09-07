
#include<bits/stdc++.h>

using namespace std;

int mcm_rec(int* p, int s, int e){
    // use the indexes as multiplication of matrices and also add 
    if(abs(s-e)<=1){
        return 0;
    }
    int min_multiplications = INT_MAX;
    int smallans=0;
    for(int k=s+1; k<e; k++){
        smallans = mcm_rec(p,s,k) + mcm_rec(p,k,e) + p[s]*p[k]*p[e];
        min_multiplications = min(smallans,min_multiplications);
    }
    return min_multiplications;
}

int main(){
    int size = 4;
    int p[] = {1, 2, 3, 4};
    cout<<mcm_rec(p,0,size-1);
}