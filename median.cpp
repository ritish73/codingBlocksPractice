#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
    int n = nums2.size();
    int a1[m],a2[n];
    // convert vector to array 
    for(int i=0;i<m;i++){
        a1[i] = nums1[i];
    }
    for(int j=0; j<n; j++){
        a2[j] = nums2[j];
    }

    int k=0;
    int sol[m+n];


    // sort after merging
    // vector<int> sol;
    int i=0,j=0;
    // int size = 0;
    while(i!=m || j!=n){
        // cout<<" i , j "<<i<<" "<<j<<endl; 
        
        if(j == n){
            // sol.push_back(nums1[i]); 
            sol[k++] = nums1[i];
            i++;
        }
        
        if(i == m){
            // sol.push_back(nums2[j]); 
            sol[k++] = nums2[j];
            j++;
        }
        
        else if(nums1[i] <= nums2[j]){
            // sol.push_back(nums1[i]);
            sol[k++] = nums1[i];
            i++;
            
        } else if(nums1[i] > nums2[j]){
            // sol.push_back(nums2[j]);
            sol[k++] = nums2[j];
            j++;
        }

        // size++;
        // cout<<"size  : "<<size<<endl;
        
    }
    // cout<<sol.size()<<endl;
    for(int i=0; i<m+n; i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;

    if((m+n)%2==0){
        int p = (m+n)/2;
        int q = p-1;
        return (double)((sol[p]+sol[q])/2);
    } else {
        int index = (m+n)/2;
        return (double)sol[index];
    }
}



int main(){
    vector<int> v1 = {0,4,5,8};
    vector<int> v2 = {9,34};
    cout << findMedianSortedArrays(v1, v2);
}