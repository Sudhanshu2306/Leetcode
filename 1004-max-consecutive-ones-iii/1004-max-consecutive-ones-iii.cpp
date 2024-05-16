class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int zero=0;
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<n){
            if(nums[j]==0) zero++;
            if(zero<=k) maxi=max(maxi,j-i+1);
            else{
                while(zero>k){
                    if(nums[i]==1) i++;
                    else{
                        zero--;
                        i++;
                    }
                }
            }
            j++;
        }
        return maxi;
    }
};