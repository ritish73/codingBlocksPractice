#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		// int i = 0;
		int count = 0;
		for(int i=0; i<n; i++){
			
			cout<<"n : "<<n<<" , i : "<<i<<endl;
			
			
			if( (1<<i) == n) {
				cout<<"count: "<<count<<endl;
				count = count+1; 
				break;
			}
			if( (1<<i) < n) continue;
			else{
				cout<<"in side else"<<endl;
				count++;
				n = (n - (1 << (i-1)));
				cout<<"reduced n : "<< n<< endl;
				i = -1; 
			}
		}

		cout<<count<<endl;

	}
	
	return 0;
}
