#include<bits/stdc++.h>
using namespace std;

void stockSpan(int *stocks, int n, int *span){
	stack<int> s;
	s.push(0);
	span[0] = 1;
	for(int i=1; i<n; i++){
		int cur_price = stocks[i];
		if(cur_price < stocks[s.top()] ){
			s.push(i);
			span[i] = 1;
		} else if(!s.empty() && cur_price >= stocks[s.top()]){
			while(!s.empty() && cur_price>=stocks[s.top()]) {
				s.pop();
			}
			span[i] = i - s.top();
		} else if(s.empty()){
			span[i] = i+1;
		}
	}
	
}








void stockSpan2Params(int *stocks, int n){
	stack<int> s;
	s.push(0);
	// span[0] = 1;
	cout<<"1 ";
	int cur_span=1;
	for(int i=1; i<n; i++){
		int cur_price = stocks[i];
		if(cur_price < stocks[s.top()] ){
			s.push(i);
			cur_span = 1;
		} else if(!s.empty() && cur_price >= stocks[s.top()]){
			while(!s.empty() && cur_price>=stocks[s.top()]) {
				s.pop();
			}
			cur_span = i - s.top();
		} else if(s.empty()){
			cur_span = i+1;
		}
		cout<<cur_span<<" ";
	}
	cout<<"END";
	
}





int main(){
	int stocks[] = {100, 80, 60, 70 , 60 , 75, 85};
//	int span[7] = {0};
	
	
	stockSpan2Params(stocks, 7);
	
//	
//	stockSpan(stocks, 7, span);
//	
//	
//	for(int i=0; i<7;i++){
//		cout<<span[i]<<" ";
//	}
}
