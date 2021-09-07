#include<bits/stdc++.h>
using namespace std;

int largestHistogramArea(int* a, int n){
	stack<int> s;
	s.push(0);
	int area = 0 , maximum_area = INT_MIN;
	int i;
	for(i=1; i<n; i++){
		
		cout<<" for i = "<<i<<" stack size is "<<s.size()<<endl;
		
		int cur_val = a[i];
		cout<<"cur val is "<<cur_val<<" and s.top is "<<s.top()<<endl;
		if(cur_val > a[s.top()]){
			s.push(i);
		} else if(cur_val <= a[s.top()]){
			
			while(!s.empty() && cur_val < a[s.top()]) {
			cout<<cur_val<< " " <<a[s.top()]<<endl;
				int top = s.top();
				s.pop();
				if(s.empty()){
					area = a[top] * i;
					cout<<"area calc if st empty "<< area << endl;
					maximum_area = max(area , maximum_area);
					
				} else{
					int l = i;
					int r = s.top();
					area = a[top] * (l - r - 1);
					cout<<"area calc if st is non empty "<< area << endl;
					maximum_area = max(area , maximum_area);
				}
				
			}
			cout<<"pushing i : "<<i<<endl;
			s.push(i);
		
		}
//		cout<<area<<endl;
		
	}
	
	while(!s.empty()){
		int top = s.top();
		s.pop();
		if(s.empty()){
			area = a[top] * i;
			cout<<area<<endl;
			
		} else{
			int l = i;
			int r = s.top();
			area = a[top] * (l - r - 1);
			cout<<area<<endl;
		}
		maximum_area = max(area , maximum_area);
	}
	
	return maximum_area;
}

int main(){
	int n = 6;

	int a[] = {2  ,3 ,4 , 5, 6};
	cout<<endl<<endl<<largestHistogramArea(a , n);
}
