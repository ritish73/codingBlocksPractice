#include<iostream>
using namespace std;
#include<vector>
#define N 10001

int p[N] = {0};

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
vector<int> factorize(int n, vector<int> primes){
	int i = 0;
	int div = primes[0];
	vector<int> ans;
	while( div*div <= n){
		if( n%div == 0 ){
			ans.push_back(div);
			while(n%div == 0) n = n/div;
		}
		i++;
		div = primes[i];
	}
	if(n!=1) ans.push_back(n);
	return ans;
}


int main(){
	int n;
	cin>>n;
	vector<int> primes;
	sieve(primes);
	vector<int> ans	= factorize(n , primes);
//	cout<<ans.size();
	for(auto i: ans){
		cout<<i<<" ";
	}
	
}
