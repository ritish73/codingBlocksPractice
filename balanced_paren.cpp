#include<iostream>
#include<stack>
using namespace std;
int main() {
	string s;
	cin>>s;
	stack<int> st;
	int i=0;
	while(s[i]!='\0'){
		if(s[i]=='{' || s[i]=='(' || s[i]=='['){
			st.push(s[i]);
		}
		else if(s[i]=='}' || s[i]==')' || s[i]==']'){

			
			if(st.top() == '{' && s[i]=='}') st.pop();
			if(st.top() == '(' && s[i]==')') st.pop();
			if(st.top() == '[' && s[i]==']') st.pop();
			else st.push(s[i]);
			

		}
		i++;
	}

	if(st.empty()) cout<<"Yes";
	else cout<<"No";
}
