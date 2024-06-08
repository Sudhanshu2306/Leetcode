class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        vector<int> l(n),r(n);

        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            l[i]=mini;
        }
        mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            r[i]=mini;
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>l[i] && nums[i]>r[i]) ans=min(ans,nums[i]+l[i]+r[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};