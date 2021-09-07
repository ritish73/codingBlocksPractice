#include<iostream>
#include<limits>
using namespace std;
#define MAX 1000
int main() {
	char s[MAX];
	cin.getline(s,MAX);

	int count[26] = {0};
	for(int i=0; s[i]!='\0'; i++){
		
		count[ s[i] - 'a']++;
	}
	// for(int i=0; i<26; i++){
	// 	cout<<count[i]<<" ";
	// }
	int ans = INT_MIN;
	char a;
	for(int i=0; i<26; i++){
		if(count[i] > ans){
			ans = count[i];
			a = 'a' + i;
		}
//		ans = max(ans,count[i]);
	}
	cout<<a;
	return 0;
}
