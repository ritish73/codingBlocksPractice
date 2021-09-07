#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s , int x){
    if(s.empty()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s , x);
    s.push(top);
}

// recursion 

void reverse(stack <int> &s) {
    cout << "fun reverse called"<<endl;
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    reverse(s);

    insertAtBottom(s , x);
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        s.push(val);
    }

    reverse(s);
    
    // now print the stack
    cout<<s.size();
    for(int i=0; i<4; i++){
    	int x = s.top();
    	cout<<x<<" ";
    	s.pop();
	}
    
}
