

#include<bits/stdc++.h>
using namespace std;

int toNum(string str){
    int pow = 1;
    int ans=0;
    for(int i=str.length()-1; i>=0; i--){
        ans += ((str[i]-'0')*pow);
        pow = pow*10;
    }
    return ans;
}

bool numcmp(pair<string, string> p1, pair<string,string> p2){
	string k1,k2;
	k1 = p1.second;
	k2 = p2.second;
    return toNum(k1) < toNum(k2);
}

bool lexicocmp(pair<string, string> p1, pair<string,string> p2){
	string k1,k2;
	k1 = p1.second;
	k2 = p2.second;
    return k1 < k2	;
}

string tokenizeStringToKey(string s, int key){

    // char* tstring = new char[strlen(str)+1];
    char* ans = strtok((char*)s.c_str(), " ");
    while(key>1){
    	ans = strtok(NULL," ");
    	key--;
	}
	return (string)ans; 

}

sortStrings(string s[], int n, int key, string b, string type){

    // tokenize every string
    pair<string,string> strpair[n];
    for(int i=0; i<n;i++){
        string getkey = tokenizeStringToKey(s[i], key);
        cout<<getkey<<endl;
        strpair[i].first = s[i];
        strpair[i].second = getkey;
    }
    
    cout<<"before sorting"<<endl;
    for(int i=0; i<n; i++){
    	cout<<"first , second  : "<<strpair[i].first<<" , "<<strpair[i].second<<endl;
	}
    
    if(type=="numeric"){
        sort(strpair, strpair+n, numcmp);
        
        cout<<"after sorting"<<endl;
    for(int i=0; i<n; i++){
    	cout<<"first , second  : "<<strpair[i].first<<" , "<<strpair[i].second<<endl;
	}
        
        
    } else {
        sort(strpair, strpair+n, lexicocmp);
    }

    if(b=="true"){
        // reverse using swap
        for(int i=0; i<n/2; i++){
            swap(strpair[i],strpair[n-i-1]);
        }
    }
    
    for(int i=0; i< n; i++){
    	cout<<strpair[i].first<<endl;
    }
    
    
}


int main(){
    int n;
    cin>>n;
    cin.get();
    string s[n];
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    
    int key; 
    string b, t;
    
    cout<<"enter key"<<endl;
    cin>>key>>b>>t;
//    cout<<"enter boolean"<<endl;
//    cin>>b;
//    cout<<"enter type : "<<type<<endl;
//    cin>>type;
	
    sortStrings(s,n,key,b,t);
//    for(int i=0; i< n; i++){
//        cout<<ans[i].first<<endl;
//    }
}
