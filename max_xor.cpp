#include<iostream>
#define ll long long
using namespace std;
int main () {
	int n,m;
	cin>>n>>m;
	ll ans[60] = {0};
	for(ll j=0; j<=59; j++){
		ll count_set_b = 0, count_clear_b = 0;
		for(ll i = n; i <= m; i++){
			if(i&(1<<j)) count_set_b++;
			else count_clear_b++;
		}
		if(count_clear_b && count_set_b) ans[j]=1;
	}

	for(ll i=0;i<=59;i++){
		cout<<ans[i]<<" ";
	}

	ll res=0;
	for(ll i=0; i<=59; i++){
		if(ans[i]){
			res += (1<<i);
			// cout<<" "<<i<<" "<<res<<endl;
		}
	}
	cout<<res;
	return 0;
}
