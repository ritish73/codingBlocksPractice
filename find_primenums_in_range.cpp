
#include<bits/stdc++.h>
using namespace std;

void prime_seive(int p[]){

    cout<<"called"<<endl;
    
    // mark all odd numbers as prime i.e 1
    // all even numbers would already be 0 as we initialized them with 0
    for(int i=3; i<=10000; i+=2){
        p[i] = 1;
    }

    // now check for each odd number i
    // and from i*i to max_range mark all multiples of that prime number 0 as those numbers whould not be prime

    for(int i=3; i<=10000; i+=2){
        if(p[i]==1){ // means we marked this odd number prime
            for(int j=i*i; j<=10000; j = j + i){
                p[j] = 0;
            }
        }
    }

    // mark p[2] as 1 as it is a prime num despite of being even
    p[2] = 1;
    p[1] = p[0] = 0;
    return;
}

int main(){

    // using prime seive
    int p[10001] = {0};

    // this function fills the array with 1 at prime position and 0 at even positions
    prime_seive(p);
    
    // for(int i=0; i<=100; i++){
    //     if(p[i]==1) cout<<i<<" ";
    // }

    // now make the cumulative sum array
    int cs[10001] = {0};
    for(int i=1; i<=10001; i++){
        cs[i] = cs[i-1] + p[i];
    }

    // for(int i=0; i<=100; i++){
    //     cout<<cs[i]<<" ";
    // }

    // now take the queries and use cs to print thier answer
    // tell how many prime numbers are there from a to b
    int Q,a,b;
    cin>>Q;
    while(Q--){
        cin>>a;
        cin>>b;
        cout<<cs[b]-cs[a-1]<<endl;
    }
    
}
