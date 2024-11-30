class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        
        int currmaxi=nums[0], currmini=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(currmaxi,currmini); 
            currmaxi=max(nums[i],currmaxi*nums[i]);
            currmini=min(nums[i],currmini*nums[i]);

            maxi=max(maxi,currmaxi);
        }
        return maxi;
    }
};