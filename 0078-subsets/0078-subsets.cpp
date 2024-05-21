class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>temp, vector<int> nums,int index){
        if(index<0){
            ans.push_back(temp);
            return;
        }
        solve(ans,temp,nums,index-1);
        temp.push_back(nums[index]);
        solve(ans,temp,nums,index-1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,nums,n-1);
        return ans;
    }
};