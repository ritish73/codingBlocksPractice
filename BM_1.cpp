
// this is wrong


// #include<iostream>
// using namespace std;

// int count(int a, int b){
// 	int ans=0;
// 	for(int i=a; i<=b; i++){
// 		cout<<i<<endl;
// 		int j=1;
// 		while(j<=32){
// 			if(i&1) {
// 				// cout<<i<<" "<<ans<<endl;
// 				ans++;
// 			}
// 			i = i >>1;
// 			j++;
// 		}
// 	}
// 	return ans;
// }

// int main() {
// 	int t=1;
// 	// cin>>t;
// 	for(int i=0; i<t; i++){
// 		int a,b;
// 		// cin>>a>>b;
// 		a = 10, b=15;
// 		if(a<b) cout<<count(a,b)<<endl;
// 		// else cout<<count(b,a)<<endl;
// 	}
// 	return 0;
// }



// this is correct



#include<iostream>
using namespace std;
int count(int a, int b){
	int ans=0;
	for(int i=a; i<=b; i++){
		int temp = i;
		int j=1;
		while(j<=32){
			if((temp&1)==1) ans++;
			temp = (temp >> 1);
			
			j++;
		}
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int a,b;
		cin>>a>>b;
		if(a<b) cout<<count(a,b)<<endl;
		else cout<<count(b,a)<<endl;
	}
	return 0;
}