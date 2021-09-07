#include<iostream>
using namespace std;

int merge(int *input, int i, int j, int k, int *in, int m, int e, int s){
	int cnt = 0;
	while(i!=m+1 || j!=e+1){
        if(i==m+1 ){
            in[k] = input[j]; k++; j++;
        }
        else if(j==e+1){
            in[k] = input[i]; k++; i++;
        }
        else if(input[i]<=input[j] ){
            in[k] = input[i];
            i++; k++;
        }
        else{
            in[k] = input[j];
            j++; k++;
            cout<<"cnt: "<<cnt<<endl;
            cnt = cnt + (m+1-i);
            cout<<"i : "<<i << " , j : "<<j<<endl;
            cout<<"cnt after add: "<<cnt<<endl;
        }
    }
    for(int i=s;i<=e;i++)
    {
        input[i] = in[i];
    }
    return cnt;
	
}

void mergesort(int input[], int s, int e, int &cnt){
    if(s>=e)
        return;
    int in[1000], k=0,i,j;
    int m = (s+e)/2;
    mergesort(input, s, m, cnt);
    mergesort(input, m+1, e, cnt);
    i=s,j=m+1,k=s;
    
    cnt += merge(input, i, j, k, in, m, e, s);
   	return;

}
 void mergeSort(int input[], int size, int &cnt){
	// Write your code here
        mergesort( input , 0 , size-1, cnt);
}  

int main(){
    // int n=6;
    int cnt=0;
    int n=8;
    int input[n] = {8,6,4,9,2,1,9,4};
    mergeSort(input, n, cnt);
//    cout<<cnt;
	for(int i=0; i<n; i++){
		cout<<input[i]<<" ";
	}

}
