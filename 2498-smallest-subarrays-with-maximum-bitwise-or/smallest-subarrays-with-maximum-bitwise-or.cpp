class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> closest(31,0);
        vector<int> ans(n,1);

        for(int i=n-1;i>=0;i--){
            for(int k=0;k<31;k++){
                if((nums[i]&(1<<k))>0) closest[k]=i;
                ans[i]=max(ans[i],closest[k]-i+1);
            }
        }
        return ans;
    }
};