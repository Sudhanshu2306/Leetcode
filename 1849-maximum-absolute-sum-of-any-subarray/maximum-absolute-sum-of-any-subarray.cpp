class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int maxi=0, mini=0;
        // run kadane twice
        for(auto it:nums){
            sum+=it;
            maxi=max(maxi,sum);
            mini=min(mini,sum);
        }
        return maxi-mini;
    }
};