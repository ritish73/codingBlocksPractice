#include<iostream>
using namespace std;
#include<stack>
// jinka next greater element ho skta hai hum unko uska nge assign krdenge and usko stack se pop krdenge
// kyunki unka nge mil chuka h
// in the end stack mein sirf vhi elements reh jayenge jinka nge nhi ho skta

//5
//18 11 16 9 14

void nextGreater(int *a, int n, int* ans){
	stack<int> s;
	s.push(0);
	for(int i=1; i<n*2; i++){
		int x = a[s.top()%n];

		while(!s.empty() && x < a[i%n]){
			// cout<<a[i]<<" ";
			ans[s.top()%n] = a[i%n];
			
			s.pop();
			cout<<"popped : "<<x<<" "<<s.size()<<endl;
			if(!s.empty()) x = a[s.top()%n];
		}
		s.push(i);
		cout<<" pushed : "<<a[i%n]<<" "<<s.size()<<endl;
	}

	while(!s.empty()){
		cout<<"when array completed : "<<a[s.top()]<<" ";
		ans[s.top()] = -1;
		s.pop();
	}
	cout<<endl;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	int ans[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	nextGreater(a , n , ans);

	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
