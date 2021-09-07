 
    #include<bits/stdc++.h>
    using namespace std;
    int usingVectors(vector<int>& height){
        int n = height.size();
        int *lm = new int[n];
        int *rm = new int[n];
        int s = 0;
        lm[0] = 0; rm[n-1] = 0;
        for(int i=1; i<n; i++){
            
            lm[i] = max(lm[i-1],height[i-1]);
            rm[n-i-1] = max(rm[n-i] , height[n-i]);
        }
        for(int i=0; i<n; i++){
            cout<<lm[i]<<" ";
        }
    cout<<endl;
        for(int i=0; i<n; i++){
            cout<<rm[i]<<" ";
        }
        
        for(int i=1; i<n-1; i++){
            if(min(lm[i],rm[i])-height[i] > 0)
            s += (min(lm[i],rm[i])-height[i]);
        }
        
        delete [] lm;
        delete [] rm;
        lm = NULL; rm = NULL;
        return s;
    }
    

    int main(){
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        // return bruteforce(height);
        cout<<endl<<usingVectors(height);
        // return _2pointer(height);
    }