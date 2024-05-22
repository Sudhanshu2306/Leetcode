class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        // set<vector<int>> st;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int asum=INT_MAX;
        for(int i=0;i<n-2;i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff<ans){
                    ans=diff;
                    asum=sum;
                } 
                if(sum<target) j++;
                else if(sum>target) k--;
                else return target;
            }
        }
        return asum;
    }
};