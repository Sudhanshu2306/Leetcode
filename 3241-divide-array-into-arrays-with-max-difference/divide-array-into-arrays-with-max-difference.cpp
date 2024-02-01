class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3!=0) return vector<vector<int>>();
        // unordered_map<int,int> mp;
        vector<vector<int>> ans(n/3,vector<int>(3));
        sort(nums.begin(),nums.end());
        int ind=0;
        for(int i=0;i<n;i+=3){
            if(i+2<n && nums[i+2]-nums[i]<=k){
                ans[ind]={nums[i],nums[i+1],nums[i+2]};
                ind++;
            }
            else return vector<vector<int>>();
        }
        return ans;
    }
};