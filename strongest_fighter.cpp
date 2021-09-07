#include<iostream>
#include<deque>

using namespace std;
#define INT_MIN -2^31
int main() {
	int n; cin>>n;
	deque<int> q;
	for(int i=0; i<n; i++){
		int ele;
		cin>>ele;
		q.push_back(ele);
	}
	int k; cin>>k;

	while(q.size() >= k){
		int maximum = INT_MIN;
		for(int i=0; i<k; i++){
			maximum = max(maximum , q.front());
			int x = q.front();
			q.pop_front();
			q.push_back(x);
		}
		cout<<maximum<<" ";
		for(int i=0; i<k; i++){
			
			int x = q.back();
			q.pop_back();
			q.push_front(x);
		}
		q.pop_front();

	}
	return 0;
}
