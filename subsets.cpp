#include<iostream>
using namespace std;


void helper(vector<vector<int>>& ans, vector<int>& nums, int s , int e, vector<int> out){
        if(s+1==e){
            
            ans.push_back(out);
            return;
        }
        
        // out.pop_back();
        helper(ans, nums, s+1, e, out);
        
        out.push_back(nums[s]);
        helper(ans, nums, s+1, e, out);
        
        
        // return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int s = 0;
        int e = nums.size()-1;
        vector<int> out;
        helper(ans, nums, s, e, out);
        return ans;
    }



int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> ans = subsets(v);
    for(int i=0; i<ans.size(); i++){

    }
}