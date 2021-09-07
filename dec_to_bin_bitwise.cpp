#include<iostream>
using namespace std;

void decToBin(int n){
    int i=1;
    while(i<=32){
        int lb = (n&1);
        cout<<lb<<" ";
        n = n>>1;
        i++;
    }
    
}

int main(){
    int n = -4;
    decToBin(n);
}