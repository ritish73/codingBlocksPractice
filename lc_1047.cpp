#include<bits/stdc++.h>
using namespace std;


string substrC(string S, int i, int j){
    
    int k = j+1;
    while(k<=S.size()-1){
        S[i] = S[k];
        i++; 
        k = k + 1;
    }
    cout<<S<<endl;
    S[i] = '\0';
    return S;
}
   
string removeDuplicates(string S) {
    if(S.size()==0 || S.size()==1){
        return S;
    }
    int i=0,j=1;
    while(j<S.size()){
        if(S[i]==S[j]){
            cout<<"calling at i , j : "<<i<<" , "<<j<<endl;
            S = substrC(S,i,j);   
            i=0;j=1;
        } else {
            i++; j++;
        }
        
                  
    }
    return S;
}



string removeDuplicates2(string S) {
    if(S.size()==0 || S.size()==1){
        return S;
    }
    stack<char> s;
    s.push(S[0]);
    int i=1;
    while(i<S.size()){

        if(s.empty()){
            s.push(S[i]);
            i++;
        }
        if(S[i] == s.top()){
            cout<<"popping : "<<s.top()<<endl;
            s.pop();
            i++;
        } else {
            cout<<"pushing : "<<S[i]<<endl;
            s.push(S[i]);
            i++;
        }
    }
    S.clear();
    while(!s.empty()){
        cout<<"S : "<<S<<endl;
        S = s.top()+S;
            s.pop();
    }
    return S;
}


int main(){
    string S="xyzzyb";
    cout<<removeDuplicates2(S);
}
