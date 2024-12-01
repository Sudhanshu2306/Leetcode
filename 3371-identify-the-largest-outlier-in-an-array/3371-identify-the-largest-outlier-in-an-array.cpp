class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return -1; 
        sort(nums.begin(),nums.end());
        double avg=accumulate(nums.begin(),nums.end(),0.0)/n;
        int outlier = nums[0];
        double maxi=fabs(nums[0] - avg);

        for(int i=1;i<n;i++){
            double deviation=fabs(nums[i]-avg);
            if (deviation>maxi) {
                maxi=deviation;
                outlier=nums[i];
            }
        }
        return outlier;
    }
};
