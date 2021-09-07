#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define N 1001
int p[N]  = {0};

void sieve(vector<int> &primes){
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
    int n,k ;
    cin>>n>>k;
    vector<int> primes;
    
    
    sieve(primes);
//    cout<<"len : "<<primes.size();

    int ans = INT_MAX;
    for(int i=0; primes[i]*primes[i] <= k; i++){
        int t = primes[i]; // t starts from value 2 as it is first prime number
        cout<<"t : "<<t<<endl;
        int occurInK;

        if(k%t == 0){
			occurInK = 0;
            while(k%t == 0){
                occurInK++;
                k = k / t;
            }
            // so this loop calculates power of 2 in k
            cout<<"occurInk : "<<occurInK<<endl;

            //now check how many times 2 comes in n!
            int p = t;
            int cnt = 0;
            while(p <= n){     // mathematical formula for finding occurences of a number (t) in a factorial
                cnt += n/p;
                p = p*t;
            }

            // this loop has calculated power of 2 in n!
            cout<<" cnt : "<<cnt<<endl;

            // ans = min(cnt(i) / occurInK(i))
             ans = min(ans, cnt/occurInK);

        }
        
    }
    
    
	// it might happen at the end one prime number is left in k
    if(k>1){
        // now we have 1 occurence of a prime number in k
        // find count of this prime number in n!
        int p = k;
        int cnt = 0;
        while(p <= n){     // mathematical formula for finding occurences of a number (t) in a factorial
            cnt += n/p;
            p = p*k;
        }
        ans = min(ans, cnt);
    }

    
    // it might also happen that there are no common factors in k and n!
    // i.e ans is unchanged ans = INT_MAX;
    if(ans == INT_MAX){
        ans = 0;
    }
    cout<<ans<<endl;
}
