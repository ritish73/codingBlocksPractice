#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define ll long long

ll a[10001], pegionhole_array[10001];

int main(){
	int n;
	cin>>n;
	int sum = 0;
	pegionhole_array[0] = 1; // there is always one null(empty) subset
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum += a[i];
		sum %= n;
		sum = (sum + n) % n;  // we are adding n in sum coz it might go negative coz of above line sum += a[i];
		pegionhole_array[sum]++;
	}

	ll answer;
	for(int i=0; i<=n; i++){ // need to add nc2 to answer if pegionhole_array[i]>=2
		if (pegionhole_array[i]>=2){
			// add nc2
			int m = pegionhole_array[i];
			answer += ( m*(m-1)) / 2;
		}
	}
	cout<<answer;
}

