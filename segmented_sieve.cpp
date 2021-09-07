#include<iostream>
#include<vector>
using namespace std;
#define N 10001


// i am denoting prime numbers with value 1 non-prime with 0

void sieve(int p[], vector<int> &primes){
	primes.push_back(2);
    for(int i=3; i<=N; i+=2){ // initially mark all odd numbers prime
        p[i] = 1;
    }

    for(int i=3; i<=N; i+=2){
        if(p[i] == 1){
            primes.push_back(i);                // naal di naal primes array nu fill kri jao
            for(int j=i*i; j<=N; j = j + i){
                p[j] = 0;
            }
        }
    }
	p[0] = p[1] =  0;
	p[2] = 1;

}


int main(){
    vector<int> primes; // this vector will contain all prime numbers till 10^5

    // int m,n;
    // cin>>m>>n;
    int p[N] = {0};
    sieve(p, primes);
//    cout<<primes.size();
//	for(int i : primes) {
//		cout<<i<<" "; 
//	}
//    
    
    // build the segment sieve array
    // lets say m = 99 , n = 150 
    // now segemnted sieve will start from m and end at n 
	//    that means their index needs to start from 99 and go till 150
	// but it would be convinient if we start array from zero
	// so we start from m-m .......  i-m.... ........ n-m 
	
	// index denotes the prime number and value at index tells if it is prime(1) or not prime(0)
	
	//	number 99 means index = 0 : segment[0] tells whether 99 is prime or not
	
	// this helps us to do proper indexing

	// now iterate over primes array
	// for each number in primes array mark multiples of that prime number in segement as non-prime by putting value 0
	
	int Q;
	cin>>Q;
	
	while(Q--){
		
		
		
		int m,n;
		cin>>m>>n;
	
		bool segment[n-m+1];
		// mark all numbers as prime initially
	    for(int i=m; i<=n; i++){
	    	segment[i-m] = 1;
		}
		
	    
		
	    for(auto x: primes){
	    	int start;
	    	if(x*x > n) break;
	    	start = (m/x)*x;  // can be proved by some examples
	    	if(x >= m && x <= n) start = x*2;
	    	// get first minimum multiple of primes[i] in segment array 
			//		i.e an element just less than m to start with 
			
			
//			cout<<start<< " "<<x<<endl;
			for(int i=start; i<=n; i+=x){
				//	segment[i] = 0;  non-prime as these are multiples of a prime number taken from primes array
				segment[i-m] = 0;
			}
	    	
		}
		
	
		for(int i=m; i<=n; i++){
			// value at index i-m tells whether number i is prime or not
	    	if(segment[i-m]==1 && i!=1) cout<<i<<endl;
	    }
		
		cout<<endl;
		
	}
	
    
}
